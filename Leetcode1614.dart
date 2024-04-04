class Solution {
  int maxDepth(String s) {
    int count = 0;
    int maxNum = 0;
    for (int i = 0; i < s.length; i++) {
      if (s[i] == '(') {
        count++;
        if (maxNum < count) maxNum = count;
      } else if (s[i] == ')') {
        count--;
      }
    }
    return maxNum;
  }
}
