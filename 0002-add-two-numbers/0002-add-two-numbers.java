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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode curr1=l1;
        ListNode curr2=l2;
        ListNode head=new ListNode(0);
        ListNode tail=head;
        int car=0;
        while(curr1!=null && curr2!=null){
            int sum=curr1.val+curr2.val+car;
            tail.next=new ListNode(sum%10);
            car=sum/10;
            tail=tail.next;
            curr1=curr1.next;
            curr2=curr2.next;
        }
        while(curr1!=null){
            int sum=curr1.val+car;
            tail.next=new ListNode(sum%10);
            car=sum/10;
            tail=tail.next;
            curr1=curr1.next;
        }
        while(curr2!=null){
            int sum=curr2.val+car;
            tail.next=new ListNode(sum%10);
            car=sum/10;
            tail=tail.next;
            curr2=curr2.next;
        }
        if(car!=0){
            tail.next=new ListNode(car);
        }
        return head.next;
    }
}