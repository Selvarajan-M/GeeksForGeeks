class LRUCache {
  private:
  
  struct Node{
      int key,val;
      Node* prev;
      Node* next;
      Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
  };
  void insertAfterHead(Node* node){
      Node* currAfterHead=head->next;
      head->next=node;
      node->prev = head;
      node->next=currAfterHead;
      currAfterHead->prev = node;
  }
  void deleteNode(Node* node){
      Node* prevNode=node->prev;
      Node* afterNode=node->next;
      prevNode->next=afterNode;
      afterNode->prev=prevNode;
  }
  Node* head;
  Node* tail;
  map<int,Node*>mpp;
  int capacity;
  
  
  public:
    LRUCache(int cap) {
        // code here
        capacity=cap;
        mpp.clear();
        head=new Node(0,0);
        tail=new Node(0,0);
        head->next=tail;
        tail->prev=head;
    }

    int get(int key) {
        // code here
        if(!mpp.count(key)) return -1;
        Node* node=mpp[key];
        deleteNode(node);
        insertAfterHead(node);
        return node->val;
    }

        
    void put(int key, int value) {
        // code here
        if(mpp.count(key)){
            Node* node=mpp[key];
            node->val=value;
            deleteNode(node);
            insertAfterHead(node);
        }
        else{
            if(mpp.size()==capacity){
                Node* node=tail->prev;
                mpp.erase(node->key);
                deleteNode(node);
                delete node;
            }
            Node* node=new Node(key,value);
            mpp[key]=node;
            insertAfterHead(node);
        }
    }
};