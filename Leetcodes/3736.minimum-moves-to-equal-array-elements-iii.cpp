/*
 * @lc app=leetcode id=3736 lang=cpp
 *
 * [3736] Minimum Moves to Equal Array Elements III
 */

// @lc code=start
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mx = nums[0];
        for (int x : nums) {
            mx = max(mx, x);
        }
        int ans = 0;
        for (int x : nums) {
            ans += mx - x;
        }
        return ans;
    }
};
// @lc code=end

