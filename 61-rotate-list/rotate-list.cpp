class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // Step 1: find length and tail
        ListNode* tail = head;
        int n = 1;
        while (tail->next) {
            tail = tail->next;
            n++;
        }

        // Step 2: make circular
        tail->next = head;

        // Step 3: find new tail
        // rotating right by k = cutting at (n - k%n - 1) steps from head
        int steps = n - k % n - 1;
        ListNode* newTail = head;
        for (int i = 0; i < steps; i++) {
            newTail = newTail->next;
        }

        // Step 4: break circle
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};