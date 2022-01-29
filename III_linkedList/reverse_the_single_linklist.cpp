#include "iostream"
using namespace std;
struct Node
{
    struct Node *next;
    int data;
};
Node *head = NULL;

void insert(Node * temp, int data)
{
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new Node;
    temp = temp->next;
    temp->data = data;
    temp->next = NULL;
}


void display(Node *temp)
{
    while(temp!=NULL)
    {
        cout<<"data : "<<temp->data<<endl;
        temp= temp->next;
    }
    cout<<"--------------------------------------\n";
}
Node *reverseTheList(Node* temp)
{
    Node *prev=NULL, *curr= temp, *next = NULL;

    while(curr->next != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    curr->next = prev;
    head = curr;
}
int main()
{
    head = new Node;
    head->data = 1;
    head->next = NULL;
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    insert(head, 6);

    display(head);
    reverseTheList(head);
    display(head);
}