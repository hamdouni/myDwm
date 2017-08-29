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
	// locate sensor index for cpu core temp
	var index int
	for i := 0; i < 128; i++ {
		p := fmt.Sprintf("/sys/class/hwmon/hwmon%d/name", i)
		if fileExists(p) {
			data, err := ioutil.ReadFile(p)
			if err != nil {
				log.Fatalf("failed to read sensor name: %s - %v", p, err)
			}
			if string(data) == "coretemp\n" {
				index = i
				break
			}
		}
	}
	inputs := []string{}
	// collect temp inputs, this may vary based on different kernels
	for i := 1; i < 128; i++ { // might have 128 cores?
		p := fmt.Sprintf("/sys/class/hwmon/hwmon%d/temp%d_input", index, i)
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

	c := float64(avg) / float64(len(inputs)) / 1000.0
	fmt.Printf("%.1f", c)
}

func fileExists(p string) bool {
	_, err := os.Stat(p)
	return !os.IsNotExist(err)
}
