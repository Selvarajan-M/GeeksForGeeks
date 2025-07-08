/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
      void inorder(Node* root,vector<int>& res)
    {
        if(!root) return;
        inorder(root->left,res);
        res.push_back(root->data);
        inorder(root->right,res);
    }  
    vector<int> inOrder(Node* root) {
        // Your code here
       vector<int>res;
       inorder(root,res);
       return res;
    }
};