package main

import "fmt"

type node struct {
	data int
	next *node
}

//insert the element in back
func insertToBack(temp *node, data int) {
	temp1 := &node{data: data, next: nil} // create new node & append it to last
	tr := temp
	for tr.next != nil {
		tr = tr.next
	}
	tr.next = temp1
}

//insert the element in front
func insertToFront(temp *node, data int) *node {
	temp1 := &node{data: data, next: temp} // create new node & append it to front & make it as a head;
	return temp1
}

//display the linkList
func display(temp *node) {
	fmt.Print("single LinkList : ")
	for temp.next != nil {
		fmt.Print(" ", temp.data)
		temp = temp.next
	}
}
func main() {

	head := &node{data: 1, next: nil} //here we r taking one object of node type , setting the param, assigning its address to the head;
	insertToBack(head, 2)
	insertToBack(head, 3)
	insertToBack(head, 4)
	insertToBack(head, 5)
	insertToBack(head, 6)

	display(head)

}
