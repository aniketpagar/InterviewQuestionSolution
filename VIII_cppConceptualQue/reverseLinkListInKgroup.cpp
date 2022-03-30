
/*

case 1 
    k = 3
    input  :  1 2 3 4 5 6 7 8 9 
    
    output :  3 2 1 6 5 4 9 8 7 

case 2
    k = 3
    input  :  1 2 3 4 5 6 7 8 9 10
    
    output :  3 2 1 6 5 4 9 8 7 10 

*/


#include "iostream"
using namespace std;
#include "vector"
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


node *reverseList(node *temp)
{
    node *curr = temp, *next = curr->next, *prev = NULL;

    while(next != NULL)
    {
        curr->next = prev;
        prev = curr;
        curr = next; 
        next = curr->next;       
    }
    curr->next = prev;
    return curr;
}

//aproach :
// break the input list in k size and reverse all the breaked list & store there heads in a vector
// then append all lists.
node* reverseListInKgroup(node* head, int k)
{

    //add the check for failure cases
    //if k == 1; return head;
    //if len <k, return head;
    
    vector<node*>heads;// stores the heads of reverse Lists
    while( head != NULL)
    {
        int i =1;
        node *temp = head;
        
        while(i != k && temp->next != NULL)
        {
            i++;
            temp= temp->next;
        }
        if( i != k)// if list size if not in multiplication of k, then we should append remaining list as it is;
        { 
            heads.push_back(head);
            break;
        }
        
        node *backUp = temp->next;  // take a backUp of Next Node
        temp->next = NULL;          // break the list
        heads.push_back(reverseList(head));
        head = backUp;              //update the head 
    }

    //connect all the breaked list 
    for (int i =0 ; i < heads.size();i++)
    {   node * temp = heads[i];
        while(temp->next != NULL) temp = temp->next;
        temp->next = heads[i+1];
    }
    return heads[0];
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
    insert(head, 10);
    cout<<"input link list :";
    display(head);
    cout<<"reverseList in K group : ";
    head = reverseListInKgroup(head, 3);
    display(head);
}

/*
OUTPUT :- 
       input link list        :  1 2 3 4 5 6 7 8 9 10
       reverseList in K group :  3 2 1 6 5 4 9 8 7 10 

*/