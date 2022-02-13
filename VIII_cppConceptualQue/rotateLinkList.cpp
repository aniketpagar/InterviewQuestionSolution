/*
    Given a list, rotate the list to the right by k places, where k is non-negative.

    For example:

    Given 1->2->3->4->5->NULL and k = 2,

    return 4->5->1->2->3->NULL.
*/
#include "iostream"
using namespace std;
struct node
{
    struct node* next;
    int data;
};
node * head = NULL;
node * head1 = NULL;

void insert(node *temp, int data)
{
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new node;
    temp = temp->next;
    temp->data = data;
    temp->next = NULL;
}
void display(node* temp)
{
    while(temp != NULL)
    {
        cout<<" "<<temp->data;
        temp = temp->next;
    }
    cout<<endl;
}



/*
    A=pointer to list
    B=number of shift operation
*/
node* rotateRight(node* A, int B) {
    //-ve check
    if(A==NULL)
        return NULL;

    //calculate length of list
    int length=1;
    node*temp1= A;
    while(temp1->next != NULL)
    {
        temp1 = temp1->next;
        length++;
    }
    //if the list is having only single element then shifting right.=/left would remain same
    if(length < 2) 
        return A;
    B = B%length;
    //if the list having shifting digit more than the length then remainder of B/length would be the shift require
    if(B ==0 )
        return A;

    node *oldHead = A;
    int i=1;//intially A pointing to head i.e i=1
    //break the list
    while(i<length-B)
    {
        i++;
        A = A->next;
    }
    node *newHead= A->next, *temp = A->next;
    A->next = NULL;
    cout<<"\n newHead for right shift list "<<newHead->data<<endl;
    while(temp->next !=NULL)
    {
        temp = temp->next;
    }
    temp->next = oldHead;

    return newHead;
}

/*
    A=pointer to list
    B=number of shift operation
*/
node* rotateLeft(node* A, int B) {
    //-ve check
    if(A==NULL)
        return NULL;

    //calculate length of list
    int length=1;
    node*temp1= A;
    while(temp1->next != NULL)
    {
        temp1 = temp1->next;
        length++;
    }
    //if the list is having only single element then shifting right.=/left would remain same
    if(length < 2) 
        return A;
    B = B%length;
    //if the list having shifting digit more than the length then remainder of B/length would be the shift require
    if(B ==0 )
        return A;

    node *oldHead = A;
    int i=1;//intially A pointing to head i.e i=1
    //break the list
    while(i<B)
    {
        i++;
        A = A->next;
    }
    node *newHead= A->next, *temp = A->next;
    A->next = NULL;
    cout<<"\n newHead for left shift list "<<newHead->data<<endl;
    while(temp->next !=NULL)
    {
        temp = temp->next;
    }
    temp->next = oldHead;

    return newHead;
}
int main()
{   
    //list 1 to rotate right
    head = new node;
    head->data = 1;
    head->next = NULL;
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    insert(head, 6);
    insert(head, 7);
    insert(head, 8);
    insert(head, 9);
    insert(head, 10);

    //list2 to rotate left 
    head1 = new node;
    head1->data = 1;
    head1->next = NULL;
    insert(head1, 2);
    insert(head1, 3);
    insert(head1, 4);
    insert(head1, 5);
    insert(head1, 6);
    insert(head1, 7);
    insert(head1, 8);
    insert(head1, 9);
    insert(head1, 10);

//both the list are same
    cout<<" display the input list"<<endl;
    display(head);

    head = rotateRight(head,2);
    cout<<" \n display the right shift list"<<endl;
    display(head);

    head1 = rotateLeft(head1,2);
    cout<<" \n display the left shift list"<<endl;
    display(head1);

}
/*
    display the input list
    1 2 3 4 5 6 7 8 9 10

    newHead for right shift list 9

    display the right shift list
    9 10 1 2 3 4 5 6 7 8

    newHead for left shift list 3

    display the left shift list
    3 4 5 6 7 8 9 10 1 2
*/