package main

import (
	"fzf"
	"fzf/protector"
)

var version string = "0.29"
var revision string = "devel"

func main() {
	protector.Protect()
	fzf.Run(fzf.ParseOptions(), version, revision)
}
