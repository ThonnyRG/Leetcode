/*
 * @lc app=leetcode id=1877 lang=cpp
 *
 * [1877] Minimize Maximum Pair Sum in Array
 */

// @lc code=start
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int minMaxPairSum = 0;

        for (int i = 0; i < n / 2; i++)
        {
            int pairSum = nums[i] + nums[n - i - 1];
            minMaxPairSum = max(minMaxPairSum, pairSum);
        }
        return minMaxPairSum;
    }
};
// @lc code=end

