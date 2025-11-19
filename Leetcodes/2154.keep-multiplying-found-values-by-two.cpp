/*
 * @lc app=leetcode id=2154 lang=cpp
 *
 * [2154] Keep Multiplying Found Values by Two
 */

// @lc code=start
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> numset(nums.begin(), nums.end());

        while (numset.count(original))
        {
            original *= 2;
        }
        return original;
    }
};
// @lc code=end

