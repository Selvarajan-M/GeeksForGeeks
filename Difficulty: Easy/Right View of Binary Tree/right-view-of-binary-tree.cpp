/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

// Should return  right view of tree
class Solution {
  public:
    // Function to return list containing elements of right view of binary tree.
    void recursion(Node* root, int level, vector<int>&ans){
        if(root == NULL){
            return;
        }
        if(level == ans.size()){
            ans.push_back(root->data);
        }
        recursion(root->right,level+1,ans);
        recursion(root->left,level+1,ans);
    }
    vector<int> rightView(Node *root) {
        // Your Code here
        vector<int>ans;
        recursion(root,0,ans);
        return ans;
        
    }
};