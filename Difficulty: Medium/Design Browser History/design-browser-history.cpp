// User function Template for C++

class BrowserHistory {
private:
    struct Node {
        string data;
        Node* back;
        Node* next;
        Node(string url) : data(url), back(nullptr), next(nullptr) {}
    };

    Node* currentPage;
public:
    BrowserHistory(string homepage) {

        currentPage=new Node(homepage);
    }
    
    void visit(string url) {
        Node* newNode=new Node(url);
        currentPage->next=newNode;
        newNode->back=currentPage;
        currentPage=newNode;
    }
    
    string back(int steps) {
        while(steps){
            if(currentPage->back)
            currentPage=currentPage->back;
            else
            break;
            steps--;
        }
        return currentPage->data;
    }
    
    string forward(int steps) {
        while(steps){
            if(currentPage->next)
            currentPage=currentPage->next;
            else
            break;
            steps--;
        }
        return currentPage->data;
    
    }
};
