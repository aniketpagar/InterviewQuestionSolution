package main

import (
	"fmt"
	"math"
)

var k = 8 //package variable same as global variable

func add(a, b int) int {
	return a + b
}

//a,b are the input & c,d are the output
func cal(a, b int) (c, d int) {
	c = a + b
	d = a - b
	return
}
func main() {
	a := 20 //function level variable , same as local variable
	b := 4

	println("sum :", add(a, b))

	m, n := cal(a, b)
	fmt.Println(m, n)

	//in go there is only one loop
	for i := 0; i < 2; i++ {
		fmt.Println("i:", i)
	}

	//print the squareroot of number
	fmt.Println(math.Sqrt(6))
	fmt.Printf("%.2g \n", math.Sqrt(6))
	fmt.Printf("%.2f \n", math.Sqrt(6))
	fmt.Printf("%.2f \n", math.Round(math.Sqrt(6)))
	fmt.Printf("%.2f \n", math.Ceil(math.Sqrt(6)))
	fmt.Printf("%.2f \n", math.Floor(math.Sqrt(6)))

	num := 1

	//if num >0
	if num > 0 {
		fmt.Printf("num %d is greated than 0 \n", num)
	} else {
		fmt.Printf("num %d is less than or equal to 0 \n", num)
	}

	//switch case
	switch num {
	case 1:
		fmt.Println("I'm in switch case 1")
		break
	case 2:
		fmt.Println("I'm in switch case 2")
		break

	default:
		fmt.Println("I'm in switch default case ")
	}

	//structure
	type aniket struct {
		a int
		b string
	}

	var aaa = aniket{2, "aniket Pagar"}
	fmt.Println(aaa)
	fmt.Println(aaa.b)
}
