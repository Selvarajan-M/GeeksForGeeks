// User function Template for C++

/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:
    vector<int> preOrder(Node* root) {
        vector<int> preorder;
        if(root == NULL) return preorder;
        
        stack<Node*> st;
        st.push(root);
        
        while(!st.empty()){
            root = st.top();
            st.pop();
            preorder.push_back(root->data);
            
            // 🔁 Push right first, then left
            if(root->right != NULL){
                st.push(root->right);
            }
            if(root->left != NULL){
                st.push(root->left);
            }
        }
        
        return preorder;
    }
};
