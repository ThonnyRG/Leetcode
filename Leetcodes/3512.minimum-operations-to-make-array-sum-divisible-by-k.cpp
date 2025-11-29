/*
 * @lc app=leetcode id=3512 lang=cpp
 *
 * [3512] Minimum Operations to Make Array Sum Divisible by K
 */

// @lc code=start
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int totalsum = reduce(nums.begin(), nums.end());

        return totalsum % k;
    }
};
// @lc code=end

