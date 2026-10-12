class ListNode {
  int val;
  ListNode? next;

  ListNode(int val) {
    this.val = val;
    next = null;
  }
}

class Solution {
  ListNode? removeZeroSumSublists(ListNode? head) {
    ListNode dummy = ListNode(0);
    ListNode cur = dummy;
    dummy.next = head;
    int prefix = 0;
    Map<int, ListNode?> m = {};

    while (cur != null) {
      prefix += cur.val;

      if (m.containsKey(prefix)) {
        cur = m[prefix]!.next!;
        int p = prefix + cur.val;

        while (p != prefix) {
          m.remove(p);
          cur = cur.next!;
          p += cur.val;
        }

        m[prefix]!.next = cur.next;
      } else {
        m[prefix] = cur;
      }

      cur = cur.next!;
    }

    return dummy.next;
  }
}
