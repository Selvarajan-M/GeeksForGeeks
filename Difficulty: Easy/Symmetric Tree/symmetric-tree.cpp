/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
  public:
    bool isSymmetric(Node *root) {
        // Code here
        return root == NULL || isSymmetricHelper(root->left,root->right);
    }
    bool isSymmetricHelper(Node* left, Node* right){
        if(left==NULL || right==NULL)
        return left==right;
        if(left->data != right->data) return false;
        return isSymmetricHelper(left->left,right->right) && isSymmetricHelper(left->right,right->left);
    }
};