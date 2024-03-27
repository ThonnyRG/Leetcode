

class Solution {
  int numSubarrayProductLessThanK(List<int> nums, int k) {
    if(k == 0)
    return 0;
    int count = 0;
    for (int i = 0; i < nums.length; i++) {
      int product = 1;
      for (int j = i; j < nums.length; j++) {
        product *= nums[j];
        if(product < k) count++; 
        else break;
      }
    }
    return count;

  }
}