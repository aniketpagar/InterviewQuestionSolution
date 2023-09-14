package main

import "fmt"

var head *node
var tail *node

type node struct {
	next *node
	prev *node
	data int
}

func insert(data int) {
	temp := head
	for temp.next != nil {
		temp = temp.next
	}
	// temp.next = &node{data:data,next:nil}
	temp.next = new(node)
	tail = temp.next
	tail.prev = temp
	tail.data = data
	tail.next = nil
}

func display() {
	temp := head
	for temp != nil {
		fmt.Print(temp.data, " ")
		temp = temp.next
	}
}
func displayReverse() {
	temp := tail
	for temp != nil {
		fmt.Print(temp.data, " ")
		temp = temp.prev
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
	head.prev = nil

	insert(2)
	insert(3)
	insert(4)
	insert(5)
	insert(6)
	fmt.Print("         list 	   : ")
	display()

	fmt.Print("\nreverse tail list : ")
	displayReverse()

}
