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
    public ListNode mergeInBetween(ListNode list1, int a, int b, ListNode list2) {
        ListNode curr = list1;
        ListNode NewNode1 = list1;
        ListNode NewNode2 = list1;
        
        for(int i=0; i<b; i++){
            if(i==a-1)  NewNode1 = curr;
            curr = curr.next;
        }
        NewNode2 = curr.next;
        NewNode1.next = list2;
        while(list2.next!=null){
            list2 = list2.next;
        } 
        list2.next = NewNode2;
        return list1;
   
      
//         Another solution

        // int count = 0;
        // ListNode curr = list1;
        // ListNode newVal = null;
        // while(curr!=null){
        //     if(count==b) newVal = curr.next;
        //     count++;
        //     curr = curr.next;
        // }
        // curr = list1; count=0;
        // while(curr!=null){
        //     count++;
        //     if(count==a) curr.next = list2;
        //     curr = curr.next; 
        // }
        // curr = list1;
        // while(curr.next!=null){
        //     curr = curr.next;
        // }
        // curr.next = newVal;
        // return list1;
    }
}
//     same approach but using for loop

        // ListNode head = list1;
        // for(int i = 1; i < a; i++) {
        //     head = head.next;
        // }
        // ListNode temp = head;
        // for(int i = 0; i < b-a+2; i++) {
        //     temp = temp.next;
        // }
        // ListNode temp2 = list2;
        // while(temp2.next != null) {
        //     temp2 = temp2.next;
        // }
        // head.next = list2;
        // temp2.next = temp;
        // return list1;

        