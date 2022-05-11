package main

import "fmt"

func add(a, b int) int {
	return a + b
}
func main() {
	var a, b int = 10, 20
	var sum int = add(a, b)

	fmt.Print("sum of ", a, " & ", b, " : ", sum)
}
