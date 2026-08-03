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
    public ListNode rotateRight(ListNode head, int k) {
        if(head==null || head.next==null || k==0){
            return head;
        }
        ListNode total=head;
        int cnt=0;
        while(total!=null){
            cnt++;
            total=total.next;
        }
        k=k%cnt;
        if(k==0){
            return head;
        }
        int minus=cnt-k;
        ListNode curr=head;
        ListNode prev=null;
        while(minus>0){
            prev=curr;
            curr=curr.next;
            minus--;
        }
        prev.next=null;
        ListNode tail=curr;
        // null pointer exception ho jata hai agr tail.next nhi kia kyuki sirf tail se null ho jaega baad me thats why
        while(tail.next!=null){
            tail=tail.next;
        }

        
        tail.next=head;
        head=curr;
        return head;
    }
}