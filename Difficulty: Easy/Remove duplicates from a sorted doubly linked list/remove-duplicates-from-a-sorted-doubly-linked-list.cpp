/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};
*/

class Solution {
  public:

    Node *removeDuplicates(struct Node *head) {
        // Your code here
        struct Node *temp=head;
        while(temp!=NULL && temp->next!=NULL){
            struct Node *nextNode=temp->next;
            while(nextNode!=NULL && nextNode->data==temp->data){
                struct Node *duplicate=nextNode;
                nextNode=nextNode->next;
                free(duplicate);
            }
            temp->next=nextNode;
            if(nextNode) nextNode->prev=temp;
            temp=temp->next;
        }
        return head;
    }
    
};