#include "iostream"
using namespace std;

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

void display_preorder(Node* temp)
{
   if (temp != NULL) 
    { 
        cout<<root->data<<endl;
        display_preorder(temp->left); 
        display_preorder(temp->right); 
    } 
}

void display_inorder(Node* temp)
{
    if (temp != NULL) 
    { 
        display_inorder(temp->left); 
        cout<<temp->data<<endl;
        display_inorder(temp->right); 
    } 	
}

void display_postorder(Node* temp)
{
   if (temp != NULL) 
    { 
        display_postorder(temp->left); 
        display_postorder(temp->right); 
        cout<<root->data<<endl;
    } 
}

//function to find the element in a tree
bool find_node(int data, Node * temp)
{
    if(temp != NULL )
    {
        if(temp->data ==  data )
            return true;
        if(data > temp->data)
            find_node(data, temp->right);
        else
            find_node(data, temp->left);
    }
}
//function to calculate height of the tree;
//NOTE : if tree only has root element then height of the should be Zero
int getMaxHeight(Node* temp)
{
    if(temp != NULL)
    {
        return max(getMaxHeight(temp->right), getMaxHeight(temp->left)) + 1;
    }
    return -1;
}


int main()
{   
    root = insert(60, root);
    insert(50,root);
    insert(55,root);
    insert(70,root);
    insert(65,root);
    insert(75,root);

    cout<<"root data : "<<root->data<<endl;
    
    //display the tree in inorder way.
    display_inorder(root);

    //find the data inside the tree
    int data = 775;

    if(find_node(data,root))
        cout<<" data : "<<data<<"  found"<<endl;
    else
        cout<<" data : "<<data<<" not found"<<endl;
    
    data = 75;

    if(find_node(data,root))
        cout<<" data : "<<data<<"  found"<<endl;
    else
        cout<<" data : "<<data<<" not found"<<endl;

    //find the height of the tree
    cout<<"height of the tree :"<<getMaxHeight(root)<<endl;
}