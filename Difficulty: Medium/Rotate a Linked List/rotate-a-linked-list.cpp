class Solution {
  public:
    Node* rotate(Node* head, int k) {
        if (head == NULL || k == 0) return head;

        // Find the length of the list
        Node* tail = head;
        int len = 1;
        while (tail->next != NULL) {
            tail = tail->next;
            len++;
        }

        k = k % len;
        if (k == 0) return head;

        // Find kth node
        Node* curr = head;
        for (int i = 1; i < k; i++) {
            curr = curr->next;
        }

        // newHead is the (k+1)th node
        Node* newHead = curr->next;
        curr->next = NULL;
        tail->next = head;

        return newHead;
    }
};
