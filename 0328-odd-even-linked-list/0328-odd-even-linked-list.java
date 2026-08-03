/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode oddEvenList(ListNode head) {
        if(head==null || head.next==null){
            return head;
        }
        ListNode odd=head;
        ListNode even=head.next;
        ListNode ev=even;
        while(ev!=null && ev.next!=null){
            odd.next=ev.next;
            odd=odd.next;
            ev.next=odd.next;
            ev=ev.next;
        }
        odd.next=even;
        return head;
    }
}