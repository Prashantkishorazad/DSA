class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null || head.next == null || k == 0) {
            return head;
        }

        // Step 1: Find length
        ListNode temp = head;
        int length = 1;
        while (temp.next != null) {
            temp = temp.next;
            length++;
        }

        // Step 2: Make circular
        temp.next = head;

        // Step 3: Find new tail
        k = k % length;
        int stepsToNewTail = length - k;

        ListNode newTail = head;
        for (int i = 1; i < stepsToNewTail; i++) {
            newTail = newTail.next;
        }

        // Step 4: Break circle
        ListNode newHead = newTail.next;
        newTail.next = null;

        return newHead;
    }
}