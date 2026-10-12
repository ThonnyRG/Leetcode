class Solution {
  List<int> sortedSquares(List<int> nums) {
    List<int> t = List<int>.filled(nums.length, 0);
    for (int i = 0; i < nums.length; i++) {
      t[i] = nums[i] * nums[i];
    }
    t.sort();
    return t;
  }
}
