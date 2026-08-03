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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        int cnt=0;
        ListNode total=head;
        while(total!=null){
            cnt++;
            total=total.next;
        }
        int minus=cnt-n;
        ListNode temp=head;
        ListNode prev=null;
        if(minus==0){   
            return head.next;
            // delete temp;
        }
        while(minus>0){
            prev=temp;
            temp=temp.next;
            minus--;           
        }
        prev.next=temp.next;
    
        return head;
    }
}