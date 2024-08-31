class Solution {
  String makeGood(String s) {
    List<String> stack = [];

    for (int i = 0; i < s.length; i++) {
      if (stack.isNotEmpty && (s.codeUnitAt(i) - stack.last.codeUnitAt(0)).abs() == 32) {
        stack.removeLast();
      } else {
        stack.add(s[i]);
      }
    }

    return stack.join();
  }
}
