class Solution {
    public ListNode deleteMiddle(ListNode head) {
        
        // Edge case: agar sirf 1 node hai
        if (head == null || head.next == null) {
            return null;
        }

        ListNode slow = head;
        ListNode fast = head;
        ListNode prev = null;

        // Middle find karo
        while (fast != null && fast.next != null) {
            prev = slow;
            slow = slow.next;
            fast = fast.next.next;
        }

        // Middle node delete
        prev.next = slow.next;

        return head;
    }
}