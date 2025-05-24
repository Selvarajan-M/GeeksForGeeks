/*Linked list Node structure

struct Node
{
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
    Node* mergeKLists(vector<Node*>& arr) {
        // Your code here
        priority_queue<pair<int,Node*>,vector<pair<int,Node*>>,greater<pair<int,Node*>>>pq;
        for(int i=0;i<arr.size();i++){
            if(arr[i]){
                pq.push({arr[i]->data,arr[i]});
            }
        }
        Node* dummyNode=new Node(-1);
        Node* temp=dummyNode;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            if(it.second->next)
            pq.push({it.second->next->data,it.second->next});
            temp->next=it.second;
            temp=temp->next;
        }
        return dummyNode->next;
    }
};