/*

Definition for Binary Tree Node
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
    void total(Node* root, vector<int>&path, vector<vector<int>>&paths){
        if(root==NULL)  return;
        path.push_back(root->data);
        if(root->left == NULL && root->right == NULL){
            paths.push_back(path);
        }
        else{
            total(root->left, path, paths);
            total(root->right, path , paths);
        }
        path.pop_back();
        
    }
    vector<vector<int>> Paths(Node* root) {
        // code here
        vector<vector<int>>paths;
        vector<int>path;
        total(root,path,paths);
        return paths;
    }
};