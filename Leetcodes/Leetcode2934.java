class Solution {
    public int minSwaps(int[] nums) {
        int ones = 0;
        for (int num : nums) {
            ones += num;
        }

        int n = nums.length;
        int res = nums.length;
        int left = 0, right = 0, cnt = 0;

        // Create a sliding window of size 'ones'
        while (right < ones) {
            cnt += nums[right % n];
            right++;
        }

        // Calculate initial "holes" in the window
        res = ones - cnt;

        // Move the sliding window across the array
        while (right < n + ones) {
            cnt += nums[right % n];
            cnt -= nums[left % n];
            right++;
            left++;
            res = Math.min(res, ones - cnt);
        }

        return res;
    }
}