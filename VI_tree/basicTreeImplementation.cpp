/*
   create new tree
   insert new element functionality
   display inorder, preorder, postOrder functionality
   find the element inside the tree
   cal height of the tree
   cal width of the tree 
*/


#include "iostream"
using namespace std;
#include "queue"
#include "list"

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
        cout<<"  "<<temp->data;
        display_preorder(temp->left); 
        display_preorder(temp->right); 
    } 
}

void display_inorder(Node* temp)
{
    if (temp != NULL) 
    { 
        display_inorder(temp->left); 
        cout<<"  "<<temp->data;
        display_inorder(temp->right); 
    } 	
}

void display_postorder(Node* temp)
{
   if (temp != NULL) 
    { 
        display_postorder(temp->left); 
        display_postorder(temp->right); 
        cout<<"  "<<temp->data;
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
//NOTE : if tree only has root element then height of the tree should be Zero
int getMaxHeight(Node* temp)
{
    if(temp != NULL)
    {
        return max(getMaxHeight(temp->right), getMaxHeight(temp->left)) + 1;
    }
    return -1;
}

int getMaxHeightWithRecursiveFunction(Node* temp)
{
    list<Node*> queue;
    int ans =-1;
    queue.push_back(temp);
    while(!queue.empty())
    {   
        ans++;
        int size = queue.size();
        for(int i =0;i<size;i++)
        {
            Node *temp1=queue.front();
            queue.pop_front();
            if(temp1->right != NULL) queue.push_back(temp1->right);
            if(temp1->left != NULL) queue.push_back(temp1->left);
        }
    }
    return ans;
}

//function to calculate width of the tree
//for concept 
//check below video link
//https://www.youtube.com/watch?v=le-ZZSQRebw
int getMaxWidthOfTheTree(Node *temp)
{
    if(temp == NULL) return -1;
    int result = 1;//if root is present i.e min width of the tree should be 1;
    queue<pair<Node*, int>> q1;
    q1.push({temp,0});
    while(!q1.empty())
    {   //calculate the width of current level & stored inside the result
        int start = q1.front().second;
        int end = q1.back().second;
        result = max(result, end - start +1);//calculate the result at every level
        int nodeInCurrentlevel = q1.size();

        //this loop is just to add all nodes of next level into the queue
        for(int i =0; i<nodeInCurrentlevel; i++)
        {
            pair<Node*, int> p1 = q1.front();
            q1.pop();
            int idx = p1.second - start;//current node idx
            if(p1.first->left != NULL) q1.push({p1.first->left, 2*idx});
            if(p1.first->right != NULL) q1.push({p1.first->right, 2*idx +1});
        }
    }
    return result;
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
    cout<<"height of the tree without recursice function :"<<getMaxHeightWithRecursiveFunction(root)<<endl;

    //find the max width of the tree
    cout<<"width of the tree :"<<getMaxWidthOfTheTree(root)<<endl;
}
