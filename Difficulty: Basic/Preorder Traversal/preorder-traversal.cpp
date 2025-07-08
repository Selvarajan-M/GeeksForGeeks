/* A binary tree node has data, pointer to left child
   and a pointer to right child

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
   void preOrder(Node* root,vector<int>& res)
    {
        if(!root) return;
        res.push_back(root->data);
        preOrder(root->left,res);
        preOrder(root->right,res);
        
    } 
    // Function to return a list containing the preorder traversal of the tree.
    vector<int> preorder(Node* root) {
        // write code here
         vector<int>res;
       preOrder(root,res);
       return res;
    }
};