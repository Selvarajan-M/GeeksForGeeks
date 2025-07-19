// User Fuction template for C++
/*
// Tree Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    // Function to return maximum path sum from any node in a tree.
    int findMaxSum(Node *root) {
        // code here
        int maxValue=INT_MIN;
        maxPathDown(root,maxValue);
        return maxValue;
    }
 private:
    int maxPathDown(Node *root,int& maxValue){
        if(root == NULL) return 0;
        int leftSum=max(0,maxPathDown(root->left,maxValue));
        int rightSum= max(0, maxPathDown(root->right,maxValue));
        maxValue=max(maxValue, (leftSum+rightSum)+root->data);
        return root->data+max(leftSum,rightSum);
    }
};