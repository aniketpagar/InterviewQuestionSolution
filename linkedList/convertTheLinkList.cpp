/*
 Given Singly linked list (1->2->3->4->5->6) , convert this list to (1->6->2->5->3->4). 
 1st's element next is nth element, 2nd's next is n-1th element and so on.

Ans Approach
1) Split linked list into 2 halfs
2) Reverse the 2nd half.
3) Now merge 1st and 2nd half again as per the question.
*/

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
        cout<<temp->data<<"    ";
        temp= temp->next;
    }
    cout<<"\n--------------------------------------\n";
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
    return curr;
}

Node* convertTheList(Node * list1, Node *list2)
{ 
    // fitst we need to add first two element here & then go inside the loop
    // reason : we need the head of newly created list;
        Node *head3 = new Node;
        Node *newHead = head3;//store the head address of list
        head3->data = list1->data;
        head3->next = new Node; head3 = head3->next;head3->data = list2->data;

        list1 = list1->next;
        list2 =  list2->next;
    //NOTE:  as per que,  both the input list should have same size
    // if not then we need to add extra checks to add remaining list.
    while(list1 != NULL && list2 != NULL)
    {

        head3->next = new Node;
        head3 = head3->next; head3->data= list1->data; // storing list1 data

        head3->next = new Node;
        head3 = head3->next; head3->data= list2->data; // storing list2 data

        list1 = list1->next;
        list2 =  list2->next;
    }
    head3->next = NULL;// to terminate the newly created list;
    return newHead;
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
    insert(head, 6);//1, 6, 2, 5, 3, 4

    cout<<"Input list \n";
    display(head);

    Node * head1;
    int i =0;
    Node *temp = head;
    //consider length is 3 / we can also calculate by writing length function
    int length = 6;
    //break the linkList
    while(i != length/2)
    {
        
        if(i == ((length/2) -1))
        { 
            head1=temp->next;
            temp->next=NULL;
            break;
        }
        temp = temp->next;
        i++;
    }

    //head1 : fist half list
    //head2 :  second half list
     cout<<"First half list : \n";
    display(head);
    cout<<"Second half list : \n";
    display(head1);
    head1=reverseTheList(head1);// reverse the second half list
    cout<<"Second half reversed list : \n";
    display(head1); //display second reversed list
    
    cout<<"Answer : \n";
    display(convertTheList(head, head1)); // convert the list as per the question
}