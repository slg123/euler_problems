package main

import (
	"fmt"
)

func a(j int) int {
	j++
	fmt.Printf("%d\n", j)
	return j
}

func b(j int) int {
	return a(a(a(a(a(j)))))
}

func c(j int) int {
	return b(b(b(b(j))))
}

func main() {
	c(c(c(c(c(0)))))
}
