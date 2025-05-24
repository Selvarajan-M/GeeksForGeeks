/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
  public:
    Node* merge(Node* head1, Node* head2) {
        // code here
     Node* t1=head1;
     Node* t2=head2;
     Node* dummyNode=new Node(-1);
     Node* res=dummyNode;
     while(t1!=NULL && t2!=NULL){
        if(t1->data < t2->data){
            res->bottom=t1;
            res=t1;
            t1=t1->bottom;
        }
        else{
            res->bottom=t2;
            res=t2;
            t2=t2->bottom;
        }
        res->next=nullptr;
     }
     if(t1) res->bottom=t1;
     else res->bottom=t2;
     return dummyNode->bottom;
    }
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) {
        // Your code here
        if(root==NULL||root->next==NULL) return root;
        Node* mergedhead=flatten(root->next);
        root=merge(root,mergedhead);
        return root;
    }
};