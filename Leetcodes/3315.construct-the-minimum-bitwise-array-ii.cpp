/*
 * @lc app=leetcode id=3315 lang=cpp
 *
 * [3315] Construct the Minimum Bitwise Array II
 */

// @lc code=start
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        for (int& p: nums) {
            int remB=(1<<countr_one((unsigned)p))>>1;
            p^=(remB)|(-(remB==0) & ~p);
        }
        return move(nums);
    }
};
// @lc code=end

