/* A binary tree node structure

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
    bool isBalanced(Node* root) {
        // Code here
        return dfsHeight(root) != -1;
    }
    int dfsHeight(Node* root) {
        if(root== NULL) return 0;
        
        int lh=dfsHeight(root->left);
        if(lh==-1) return -1;
        int rh=dfsHeight(root->right);
        if(rh==-1) return -1;
        
        if(abs(lh-rh) > 1) return -1;
        
        return max(lh,rh)+1;
    }
};