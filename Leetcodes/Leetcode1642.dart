import 'dart:collection';

class Solution {
  int furthestBuilding(List<int> h, int b, int l) {
    PriorityQueue<int> p = PriorityQueue<int>((a, b) => b.compareTo(a));

    int i = 0, diff = 0;
    for (i = 0; i < h.length - 1; i++) {
      diff = h[i + 1] - h[i];

      if (diff <= 0) {
        continue;
      }

      b -= diff;
      p.add(diff);

      if (b < 0) {
        b += p.removeFirst();
        l--;
      }

      if (l < 0) {
        break;
      }
    }

    return i;
  }
}
