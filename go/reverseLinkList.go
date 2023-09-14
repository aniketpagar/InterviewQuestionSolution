package main

import "fmt"

var head *node

type node struct {
	next *node
	data int
}

func insert(data int) {
	temp := head
	for temp.next != nil {
		temp = temp.next
	}
	// temp.next = &node{data:data,next:nil}
	temp.next = new(node)
	temp = temp.next
	temp.data = data
	temp.next = nil
}

func display() {
	temp := head
	for temp != nil {
		fmt.Print(temp.data, " ")
		temp = temp.next
	}
}
func reverseLinkList() {
	curr := head
	var prev *node
	next := head.next

	for next != nil {
		curr.next = prev
		prev = curr
		curr = next
		next = next.next
	}

	head = curr
	head.next = prev
}
func main() {
	head = new(node)
	head.data = 1
	head.next = nil
	insert(2)
	insert(3)
	insert(4)
	insert(5)
	insert(6)
	fmt.Print("list : ")
	display()
	reverseLinkList()
	fmt.Print("\nreverse list : ")
	display()

}
