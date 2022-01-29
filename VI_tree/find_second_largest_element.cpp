/****************************************************************************
File name: find_second_largest_element.cpp
Author: aniket
*****************************************************************************/

#include "iostream"
using namespace std;
#include "queue"

//Node data structure
typedef struct Node
{
    struct Node *right, * left;
    int data;
};

//paramter root is having a global scope 
//we should avoid using root as local varible in all function
Node *root;

//function to insert element in the tree
Node* insert(int data, Node *temp)
{
    //add the node here.
    if(temp == NULL)
    { 
        cout<<" insert : "<<data<<endl;
        temp = new Node;
        temp->data = data;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
    
    //recursive call
    if( data > temp->data)
        temp->right = insert(data, temp->right);
    else
        temp->left = insert(data, temp->left);


    return temp; //this is require to conncet all nodes
}


void find_second_largest(Node* temp)
{
    //assumption :tree should have more than 2 elements
    int largest = 0, secLargest = 0;
    while(temp != NULL)
     {
         if(temp->data > largest)
         {
             secLargest = largest;
             largest = temp->data;
         }
         temp =temp->right;
     }    
     cout<<"second Largest : "<<secLargest<<endl;
}

int main()
{   
    root = insert(60, root);
    insert(50,root);
    insert(55,root);
    insert(70,root);
    insert(65,root);
    insert(75,root);
    find_second_largest(root);
}
/*
Output : 
insert : 60
 insert : 50
 insert : 55
 insert : 70
 insert : 65
 insert : 75
second Largest : 70
*/
