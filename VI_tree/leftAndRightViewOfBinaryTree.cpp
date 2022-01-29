/*
tree -->
                   50
            30            70
         20    40      60     80
                                 150



*/
#include "iostream"
using namespace std;
#include "queue"

//Node data structure
struct Node
{
    struct Node *right, * left;
    int data;
};

//paramter root is having a global scope 
//we should avoid using root as local varible in all function
Node *root;

//function to insert element in the tree
Node* insert( Node *temp,int data)
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
        temp->right = insert( temp->right,data);
    else
        temp->left = insert( temp->left,data);


    return temp; //this is require to conncet all nodes
}

//function to display left view of tree
void displayLeftViewOfTree(Node* temp)
{
    cout<<" display the left view of binary tree =>"<<endl;
    if(temp != NULL)
    {
        queue<Node*>q1;
        q1.push(temp);

        while(!q1.empty())
        {
            int numOfNodeInCurrentLevel = q1.size();
            cout<<q1.front()->data<<endl;
            //get all node of next level into the queue
            for(int i =0; i< numOfNodeInCurrentLevel; i++)
            {
                auto tem = q1.front();
                q1.pop();
                if(tem->left != NULL) q1.push(tem->left);
                if(tem->right != NULL) q1.push(tem->right);
            }
        }
    }
}

//function to display right view of tree
void displayRightViewOfTree(Node* temp)
{
    cout<<" display the right view of binary tree =>"<<endl;
    if(temp != NULL)
    {
        queue<Node*>q1;
        q1.push(temp);

        while(!q1.empty())
        {
            int numOfNodeInCurrentLevel = q1.size();
            cout<<q1.back()->data<<endl;
            //get all node of next level into the queue
            for(int i =0; i< numOfNodeInCurrentLevel; i++)
            {
                auto tem = q1.front();
                q1.pop();
                if(tem->left != NULL) q1.push(tem->left);
                if(tem->right != NULL) q1.push(tem->right);
            }
        }
    }
}
int main()
{
     root =insert(root,50);
    insert(root,30);
    insert(root,20);
    insert(root,40);
    insert(root,70);
    insert(root,60);
    insert(root,80);
    insert(root,150);

    displayLeftViewOfTree(root);
    displayRightViewOfTree(root);

}