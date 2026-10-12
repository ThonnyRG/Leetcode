class Solution {
int largestPerimeter(List<int> nums) {
  int len = nums.length;
  nums.sort();
  List<int> arr = List.filled(len, 0);
  arr[0] = nums[0];
  for (int i = 1; i < len; i++) {
    arr[i] += arr[i - 1] + nums[i];
  }
  int ans = -1;
  for (int i = 2; i < len; i++) {
    if (arr[i] - arr[i - 1] < arr[i - 1]) {
      ans = ans > arr[i] ? ans : arr[i];
    }
  }
  return ans == -1 ? -1 : ans;
}
}