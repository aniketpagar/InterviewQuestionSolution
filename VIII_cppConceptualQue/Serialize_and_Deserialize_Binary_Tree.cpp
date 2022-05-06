#include "iostream"
using namespace std;

//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Codec {
    
    int in;
    
    TreeNode* deHelper(string s){
        if(in>=s.size())return NULL;
        if(s[in]=='$'){
            in+=2;
            return NULL;
        }
        string tmp="";
        while(s[in]!=','){
            tmp+=s[in++];
        }
        TreeNode* root=new TreeNode(stoi(tmp));
        in++;
        root->left=deHelper(s);
        root->right=deHelper(s);
        return root;
    }
    
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root){
            return "$";
        }
        return to_string(root->val)+','+serialize(root->left)+","+serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        in=0;
        return deHelper(data);
    }
};