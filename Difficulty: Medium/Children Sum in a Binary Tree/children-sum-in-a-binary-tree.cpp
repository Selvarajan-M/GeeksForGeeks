/*Complete the function below

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){80
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    // Function to check whether all nodes of a tree have the value
    // equal to the sum of their child nodes.
    bool checkTreeProperty(Node* root){
        if (root == NULL) return true;

        // Leaf node
        if (root->left == NULL && root->right == NULL)
            return true;

        int left_data = (root->left) ? root->left->data : 0;
        int right_data = (root->right) ? root->right->data : 0;

        // Current node must be equal to the sum of its children
        if (root->data != left_data + right_data)
            return false;

        // Recursively check for left and right subtrees
        return checkTreeProperty(root->left) && checkTreeProperty(root->right);
    }
    int isSumProperty(Node *root) {
        // Add your code here
        return checkTreeProperty(root) ? 1 :0;
        

    }
};