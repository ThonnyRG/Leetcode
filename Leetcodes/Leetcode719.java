import java.util.Arrays;

class Solution {
    public int position(int[] nums, int m) {
        int ans = 0;
        for (int i = 0; i < nums.length - 1; ++i) {
            int index = Arrays.binarySearch(nums, nums[i] + m + 1);
            if (index < 0) index = -index - 1;
            ans += (index - 1 - i);
        }
        return ans;
    }
    
    public int smallestDistancePair(int[] nums, int k) {
        Arrays.sort(nums);
        int l = 0, n = nums.length, r = nums[n-1] - nums[0];
        while (r - l > 1) {
            int m = l + (r - l) / 2;
            if (position(nums, m) >= k) {
                r = m;
            } else {
                l = m;
            }
        }
        if (position(nums, l) >= k) {
            return l;
        } else if (position(nums, r) >= k) {
            return r;
        }
        return 0;
    }
}