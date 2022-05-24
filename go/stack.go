package main

import "fmt"

type stack struct {
	data []int
}

var stackSize int = 4

func (s *stack) push(data int) {
	if len(s.data) >= stackSize {
		fmt.Println(" stack overflow")
		return
	}
	s.data = append(s.data, data)
}

//pop will remove value from the end, return the value
func (s *stack) pop() int {

	l := len(s.data) - 1
	if l < 0 {
		fmt.Println("stack is empty")
		return -1
	}
	remove := s.data[l]
	s.data = s.data[:l]
	return remove
}
func main() {

	mystack := stack{}
	mystack.push(1)
	mystack.push(2)
	mystack.push(3)
	mystack.push(4)
	mystack.push(5)
	fmt.Println(mystack)
	mystack.pop()
	fmt.Println(mystack)
	mystack.pop()
	mystack.pop()
	mystack.pop()
	mystack.pop()

}
