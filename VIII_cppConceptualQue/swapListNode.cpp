/*
Given a singly linked list

    L: L0 → L1 → … → Ln-1 → Ln,
reorder it to:

    L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …
You must do this in-place without altering the nodes’ values.

For example,

Given {1,2,3,4}, reorder it to {1,4,2,3}.


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

node* swap(node* temp1, node* temp2)
{
    temp1->next=temp2->next;
    temp2->next = temp1;
    return temp2;
}
node* swapPair(node* temp)
{

    bool flag = 1;
    node* start = new node;
    start->next = temp;//head is no longer a valid head
    node *cur = start;
    while(cur->next != NULL && cur->next->next != NULL)
    {

        cur->next = swap(cur->next, cur->next->next);
        cur=cur->next->next;
    }
    return start->next;
}
int main()
{
    head = new node;
    head->data = 1;
    head->next = NULL;
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    insert(head, 6);
    cout<<"input list -> ";
    display(head);
    head=swapPair(head);
    cout<<"output list -> ";
    display(head);
}
/*
output
    input list ->  1 2 3 4 5 6
    output list ->  2 1 4 3 6 5
*/