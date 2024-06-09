public class Solution {
    public int subarraysDivByK(int[] nums, int k) {
        int count = 0;
        
        // Iterate through all possible subarrays
        for (int i = 0; i < nums.length; i++) {
            int sum = 0;
            for (int j = i; j < nums.length; j++) {
                sum += nums[j];
                // Check if the sum is divisible by k
                if (sum % k == 0) {
                    count++;
                }
            }
        }
        
        return count;
    }
}