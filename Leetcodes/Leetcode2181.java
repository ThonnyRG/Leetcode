/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
}
 */
class Solution {
    public ListNode mergeNodes(ListNode head) {
        ListNode l2 = head;
        ListNode head2=l2;
        int sum=0;
        ListNode curr=head.next;
        while(curr!=null){
            if(curr.val==0){
            l2.val=sum;
            sum=0;
            if(curr.next==null)
            l2.next=null;
            else
            l2=l2.next;
            }
            if(curr.val!=0)
            sum=sum+curr.val;
            curr=curr.next;
        }
        return head2;
    }
}