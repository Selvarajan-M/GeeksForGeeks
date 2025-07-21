/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new root
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    
    bool isLeaf(Node* root){
        return (root->left==NULL && root->right==NULL);
    }
    void addLeftBoundary(Node* root, vector<int>&res){
        Node* curr = root->left;
        while(curr != NULL){
            if(isLeaf(curr) == false) res.push_back(curr->data);
            if(curr->left != NULL) curr=curr->left;
            else curr=curr->right;
        }
    }
    void addRightBoundary(Node* root, vector<int>&res){
        Node* curr=root->right;
        vector<int>tmp;
        while(curr != NULL){
            if(isLeaf(curr)== false) tmp.push_back(curr->data);
            if(curr->right != NULL) curr=curr->right;
            else curr=curr->left;
        }
        for(int i=tmp.size()-1;i>=0;i--){
            res.push_back(tmp[i]);
        }
    }
    void addLeaves(Node* root, vector<int>&res){
        if(isLeaf(root)){
            res.push_back(root->data);
            return;
        }
        if(root->left!=NULL) addLeaves(root->left,res);
        if(root->right !=NULL) addLeaves(root->right, res);
    }
    
    
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int>ans;
        if(isLeaf(root) == false) ans.push_back(root->data);
        addLeftBoundary(root, ans);
        addLeaves(root, ans);
        addRightBoundary(root, ans);
        return ans; 
    }
};