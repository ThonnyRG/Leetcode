/*
 * @lc app=leetcode id=1351 lang=cpp
 *
 * [1351] Count Negative Numbers in a Sorted Matrix
 */

// @lc code=start
class Solution {
public:
    int first_lower(vector<int>& x) {
        reverse(x.begin(), x.end());
        int l = 0, r = x.size() - 1, res = -1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (x[m] < 0) {
                res = m;
                l = m + 1;
            } else 
                r = m - 1;
        }
        return res + 1;
    }
    int countNegatives(vector<vector<int>>& grid) {
        int res = 0;
        for (auto& x : grid) 
            res += first_lower(x);
        return res;
    }
};
// @lc code=end

