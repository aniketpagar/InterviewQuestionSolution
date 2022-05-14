package main
import "fmt"

type node struct{
	data int
	next *node
}
func insert(temp *node, data1 int){
	for temp.next != nil{
		temp=temp.next
	}
	temp.next = &node{data:data1,next:nil}
}
func display(temp*node){
	for temp!=nil{
		fmt.Print(" ",temp.data)
		temp= temp.next
	}
}
func reverseList(temp *node)*node{

	var prev *node = nil
	curr := temp
	var next *node = curr.next

	for next !=nil{
		curr.next = prev
		prev = curr
		curr= next
		next = curr.next;
	}

	curr.next=prev;
	return curr
}
func main(){

	head:=&node{data:1,next:nil}
	insert(head,2)
	insert(head,3)
	insert(head,4)
	insert(head,5)
	fmt.Print(" LinkList : ")
	display(head)

	head = reverseList(head)
	fmt.Println()

	fmt.Print(" reverse LinkList : ")
	display(head)

}