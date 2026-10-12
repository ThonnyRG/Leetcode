import 'dart:collection';

class Solution {
  int maxSubarrayLength(List<int> nums, int k) {
    int n = nums.length;
    int l = 0, r = 0, ans = 0;
    var freq = HashMap<int, int>();

    while (r < n) {
      freq[nums[r]] = (freq[nums[r]] ?? 0) + 1;
      while (l <= r && freq[nums[r]]! > k) {
        freq[nums[l]] = (freq[nums[l]] ?? 0) - 1;
        if (freq[nums[l]] == 0) {
          freq.remove(nums[l]);
        }
        l++;
      }
      ans = (r++ - l + 1).compareTo(ans) > 0 ? r - l : ans;
    }

    return ans;
  }
}