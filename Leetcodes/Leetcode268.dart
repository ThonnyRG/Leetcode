import 'dart:core';

class Solution {
  int missingNumber(List<int> nums) {
    nums.sort();
    int n = nums.length;
    for (int i = 0; i < n; i++) {
      if (nums[i] != i) {
        return i;
      }
    }
    return n;
  }
}
