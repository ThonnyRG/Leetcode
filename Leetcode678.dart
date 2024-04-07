class Solution {
  bool checkValidString(String s) {
    int leftMin = 0, leftMax = 0;

    for (var c in s.runes) {
      if (String.fromCharCode(c) == '(') {
        leftMin++;
        leftMax++;
      } else if (String.fromCharCode(c) == ')') {
        leftMin--;
        leftMax--;
      } else {
        leftMin--;
        leftMax++;
      }
      if (leftMax < 0) return false;
      if (leftMin < 0) leftMin = 0;
    }

    return leftMin == 0;
  }
}
