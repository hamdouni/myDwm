package main

import (
	"fmt"
	"io/ioutil"
	"log"
	"os"
	"strconv"
	"strings"
)

func main() {
	inputs := []string{}
	// collect temp inputs, this may vary based on different kernels
	for i := 1; i < 128; i++ { // might have 128 cores?
		p := fmt.Sprintf("/sys/class/hwmon/hwmon0/temp%d_input", i)
		if !fileExists(p) {
			break
		}
		inputs = append(inputs, p)
	}
	if len(inputs) == 0 {
		// look elsewhere
		p := "/sys/class/thermal/thermal_zone0/temp"
		if fileExists(p) {
			inputs = append(inputs, p)
		}
	}
	if len(inputs) == 0 {
		log.Fatal("could not determine CPU temperature inputs")
	}
	var avg int
	for _, in := range inputs {
		data, err := ioutil.ReadFile(in)
		if err != nil {
			log.Fatalf("failed to read temperature input: %s - %v", in, err)
		}

		s := strings.TrimSpace(string(data))
		i, err := strconv.Atoi(s)
		if err != nil {
			log.Fatalf("failed to read temperature input: %s - %v", in, err)
		}
		avg += i
	}

	c := avg / len(inputs) / 1000
	fmt.Println(c)
}

func fileExists(p string) bool {
	_, err := os.Stat(p)
	return !os.IsNotExist(err)
}
