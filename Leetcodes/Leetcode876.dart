class ListNode {
  int val;
  ListNode? next;

  ListNode(int val) {
    this.val = val;
    next = null;
  }
}

class Solution {
  ListNode? middleNode(ListNode? head) {
    if (head == null || head.next == null) return head;

    ListNode? fast = head;
    ListNode? slow = head;

    while (fast != null) {
      fast = fast.next;
      if (fast != null) {
        fast = fast.next;
        slow = slow!.next;
      }
    }

    return slow;
  }
}
