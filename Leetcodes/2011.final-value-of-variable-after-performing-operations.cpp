/*
 * @lc app=leetcode id=2011 lang=cpp
 *
 * [2011] Final Value of Variable After Performing Operations
 */

// @lc code=start
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int ans = 0;
        for (string x : operations) ans += (x[1] == '+' ? 1 : -1);
        return ans;
    }
};
// @lc code=end

