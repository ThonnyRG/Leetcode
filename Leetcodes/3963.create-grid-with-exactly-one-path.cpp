/*
 * @lc app=leetcode id=3963 lang=cpp
 *
 * [3963] Create Grid With Exactly One Path
 */

// @lc code=start
class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m);
        grid[0] = string(n, '.');
        string row = string(n - 1, '#') + '.';
        for (int i = 1; i < m; i++) {
            grid[i] = row;
        }
        return grid;
    }
};
// @lc code=end

