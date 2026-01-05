/*
 * @lc app=leetcode id=1975 lang=cpp
 *
 * [1975] Maximum Matrix Sum
 */

// @lc code=start
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long res = 0;
        int flippables = 0, smallest = INT_MIN;
        for (auto &row: matrix) {
            for (int n: row) {
                if (n <= 0) {
                    flippables++;
                    smallest = max(smallest, n);
                    res -= n;
                }
                else {
                    res += n;
                    smallest = max(smallest, -n);
                }
            }
        }
        return res + (flippables & 1 ? smallest * 2 : 0);
    }
};
// @lc code=end

