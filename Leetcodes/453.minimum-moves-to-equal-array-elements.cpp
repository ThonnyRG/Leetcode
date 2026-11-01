/*
 * @lc app=leetcode id=453 lang=cpp
 *
 * [453] Minimum Moves to Equal Array Elements
 */

// @lc code=start
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int lo = ranges::min(nums), moves = 0;
        for (int x : nums) moves += x - lo;
        return moves;
    }
};
// @lc code=end

