class Solution {
  String removeKdigits(String num, int k) {
    List<String> stk = [];
    int n = num.length;
    if (k >= n) {
      return "0";
    }
    for (int i = 0; i < n; i++) {
      while (stk.isNotEmpty && stk.last.compareTo(num[i]) > 0 && k != 0) {
        stk.removeLast();
        k--;
      }
      if (stk.isNotEmpty || num[i] != '0') {
        stk.add(num[i]);
      }
    }
    StringBuffer str = StringBuffer();
    while (stk.isNotEmpty && k > 0) {
      stk.removeLast();
      k--;
    }
    if (stk.isEmpty) {
      return "0";
    }
    for (int i = stk.length - 1; i >= 0; i--) {
      str.write(stk[i]);
    }
    return str.toString();
  }
}
