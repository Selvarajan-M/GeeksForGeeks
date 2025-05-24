/*
The structure of linked list is the following

struct Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* findMiddle(Node* head){
        Node* slow=head;
        Node* fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    Node* mergeTwoLists(Node* list1, Node* list2){
        Node* dummyNode=new Node(-1);
        Node* temp=dummyNode;
        while(list1!=NULL && list2!=NULL){
            if(list1->data<list2->data){
                temp->next=list1;
                temp=list1;
                list1=list1->next;
            }
            else{
                temp->next=list2;
                temp=list2;
                list2=list2->next;
            }
            
        }
        if(list1) temp->next=list1;
        else temp->next=list2;
        return dummyNode->next;
    }
    // Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // your code here
        if(head==NULL || head->next==NULL) return head;
        Node* middle=findMiddle(head);
        Node* right=middle->next;
        middle->next=nullptr;
        Node* left=head;
        left=mergeSort(left);
        right=mergeSort(right);
        return mergeTwoLists(left,right);
    }
};