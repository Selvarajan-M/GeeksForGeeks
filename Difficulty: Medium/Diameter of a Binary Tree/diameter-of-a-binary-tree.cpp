/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* newNode(int val) {
    return new Node(val);
}
*/

class Solution {
  public:
    int diameter(Node* root) {
        // Your code here
        int diameter=0;
        height(root, diameter);
        return diameter;
    }
  private:
    int height(Node* root, int& diameter){
        if(root == NULL)
        return 0;
        int lh=height(root->left, diameter);
        int rh=height(root->right, diameter);
        diameter=max(diameter, lh+rh);
        return 1+max(lh,rh); 
    }

};