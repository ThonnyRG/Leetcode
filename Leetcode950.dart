import 'dart:collection';

class Solution {
  List<int> deckRevealedIncreasing(List<int> deck) {
    deck.sort();
    Queue<int> dq = Queue<int>();
    int n = deck.length;
    dq.addFirst(deck[n - 1]);
    for (int i = n - 2; i >= 0; i--) {
      int x = dq.removeLast();
      dq.addFirst(x);
      dq.addFirst(deck[i]);
    }

    List<int> ans = List<int>.filled(n, 0);
    int index = 0;
    while (dq.isNotEmpty) {
      ans[index++] = dq.removeFirst();
    }
    return ans;
  }
}
