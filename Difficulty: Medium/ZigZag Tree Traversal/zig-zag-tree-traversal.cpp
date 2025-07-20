/*Structure of the node of the binary tree is as
struct Node {
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
    // Function to store the zig zag order traversal of tree in a list.
    vector<int> zigZagTraversal(Node* root) {
        vector<int> result;
        if (root == NULL)
            return result;

        queue<Node*> nodesQueue;
        nodesQueue.push(root);
        bool leftToRight = true;

        while (!nodesQueue.empty()) {
            int size = nodesQueue.size();
            vector<int> row(size);

            for (int i = 0; i < size; i++) {
                Node* node = nodesQueue.front();
                nodesQueue.pop();

                // Determine the correct index for zig-zag
                int index = (leftToRight) ? i : (size - 1 - i);
                row[index] = node->data;

                if (node->left)
                    nodesQueue.push(node->left);
                if (node->right)
                    nodesQueue.push(node->right);
            }

            // Add current level nodes to the result
            for (int val : row)
                result.push_back(val);

            // Flip the direction
            leftToRight = !leftToRight;
        }

        return result;
    }
};
