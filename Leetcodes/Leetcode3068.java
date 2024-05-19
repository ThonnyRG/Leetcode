class Solution {
    public long maximumValueSum(int[] nums, int k, int[][] edges) {
        int n = nums.length;
        long[] getXORDiff = new long[n];
        for (int i = 0; i < n; ++i)
            getXORDiff[i] = (nums[i]^k)-nums[i];
        Arrays.sort(getXORDiff);
        long maxSum = 0;
        for (int x : nums)
            maxSum+=x;
        for (int i = n-1; i >= 1; i-=2) {
            if (getXORDiff[i]+getXORDiff[i-1]<0)
                return maxSum;
            maxSum += getXORDiff[i]+getXORDiff[i-1];
        }
        return maxSum;
    }
}