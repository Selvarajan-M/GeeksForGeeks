/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
public:
    int addHelper(Node* temp, int& carry) { // Pass carry by reference
        if (temp == NULL) {
            carry = 1; // Set carry to 1 to add 1 at the least significant digit
            return 0;
        }
        
        // Recurse to the next node
        int nextCarry = addHelper(temp->next, carry);
        
        // Calculate new digit and carry
        int sum = temp->data + carry;
        temp->data = sum % 10;
        carry = sum / 10;
        
        return carry;
    }
    
    Node* addOne(Node* head) {
        if (head == NULL) {
            return new Node(1); // Empty list case
        }
        
        int carry = 0;
        int finalCarry = addHelper(head, carry);
        
        // If there is a carry after processing, add a new node
        if (finalCarry == 1) {
            Node* newNode = new Node(1);
            newNode->next = head;
            head = newNode;
        }
        
        return head;
    }
};