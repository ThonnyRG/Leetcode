import 'dart:collection';

class Solution {
  int openLock(List<String> deadends, String target) {
    Set<String> deadSet = Set.from(deadends);
    if (deadSet.contains("0000")) return -1;
    Queue<String> q = Queue.of(["0000"]);
    for (int steps = 0; q.isNotEmpty; ++steps) {
      for (int i = q.length; i > 0; --i) {
        String curr = q.removeFirst();
        if (curr == target) return steps;
        for (String nei in neighbors(curr)) {
          if (deadSet.contains(nei)) continue;
          deadSet.add(nei); // Marked as visited
          q.add(nei);
        }
      }
    }
    return -1;
  }

  List<String> neighbors(String code) {
    List<String> result = [];
    for (int i = 0; i < 4; i++) {
      int x = int.parse(code[i]);
      for (int diff = -1; diff <= 1; diff += 2) {
        int y = (x + diff + 10) % 10;
        result.add('${code.substring(0, i)}$y${code.substring(i + 1)}');
      }
    }
    return result;
  }
}
