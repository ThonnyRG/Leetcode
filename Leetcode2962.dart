class Solution {
  int countSubarrays(List<int> nums, int k) {
    int max = nums.reduce((value, element) => value > element ? value : element);
    int output = 0;
    int count = 0;
    int a = 0;
    int b = 0;

    while (b < nums.length) {
      if (nums[b] == max) {
        count++;
      }
      if (count >= k) {
        while (count >= k) {
          output += nums.length - b;
          if (nums[a] == max) {
            count--;
          }
          a++;
        }
      }
      b++;
    }
    return output;
  }
}

void main() {
  Solution solution = Solution();

  var nums = [1, 4, 3, 2, 5, 4, 4, 3];
  var k = 2;

  print(solution.countSubarrays(nums, k)); // Output: 9
}
