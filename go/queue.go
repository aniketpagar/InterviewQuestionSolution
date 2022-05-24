package main

import "fmt"

type queue struct {
	data []int
}

var queueSize int = 4

func (s *queue) enqueue(data int) {
	if len(s.data) >= queueSize {
		fmt.Println(" queue overflow")
		return
	}
	s.data = append(s.data, data)
}

//dequeue will remove value from the end, return the value
func (s *queue) dequeue() int {

	l := len(s.data) - 1
	if l < 0 {
		fmt.Println("queue is empty")
		return -1
	}
	remove := s.data[0]
	s.data = s.data[1 : l+1]
	return remove
}
func main() {

	myQueue := queue{}
	myQueue.enqueue(1)
	myQueue.enqueue(2)
	myQueue.enqueue(3)
	myQueue.enqueue(4)
	myQueue.enqueue(5)
	fmt.Println(myQueue)
	myQueue.dequeue()
	fmt.Println(myQueue)
	myQueue.dequeue()
	fmt.Println(myQueue)
	myQueue.dequeue()
	fmt.Println(myQueue)
	myQueue.dequeue()
	fmt.Println(myQueue)
	myQueue.dequeue()

}
