/*
Problem Description

Given a linked list A of length N and an integer B.

You need to find the value of the Bth node from the middle towards the beginning of the Linked List A.

If no such element exists, then return -1.

NOTE:

Position of middle node is: (N/2)+1, where N is the total number of nodes in the list.


Problem Constraints
1 <= N <= 105
1<= Value in Each Link List Node <= 103
1 <= B <= 105


Input Format
First argument is the head pointer of the linkedlist A.

Second argument is an integer B.



Output Format
Return an integer denoting the value of the Bth from the middle towards the head of the linked list A. If no such element exists, then return -1.



Example Input
Input 1:

 A = 3 -> 4 -> 7 -> 5 -> 6 -> 1 6 -> 15 -> 61 -> 16
 B = 3
 Input 2:

 A = 1 -> 14 -> 6 -> 16 -> 4 -> 10
 B = 2
 Input 3:

 A = 1 -> 14 -> 6 -> 16 -> 4 -> 10
 B = 10


Example Output
Output 1:

 4
 Output 2:

 14
 Output 3:

 -1


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

int kthElemFromMidTwrdsRight(node* temp1, int B) {

    int length =0;
    node *temp=temp1;
    //calculate length
    while(temp !=NULL)
    {
        length++;
        temp=temp->next;
    }
    //find the mid
    int mid=length/2 +1;
    
    int ans=0,i=1;

    //to check -ve scenario
    if(B>mid || length==1)
     return -1;
    
    //to find the ans
    while(i <= mid-B)
    {
        ans= temp1->data;
        temp1= temp1->next;
        i++;
    }
    return ans;
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
    insert(head, 7);
    insert(head, 8);
    insert(head, 9);
    
    display(head);
    cout<<" 2nd Element from mid towards beginning of list : "<<kthElemFromMidTwrdsRight(head, 2)<<endl;


}
/*
output
 1 2 3 4 5 6 7 8 9
 2nd Element from mid towards beginning of list : 3

*/