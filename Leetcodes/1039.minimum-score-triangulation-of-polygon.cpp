/*
 * @lc app=leetcode id=1039 lang=cpp
 *
 * [1039] Minimum Score Triangulation of Polygon
 */

// @lc code=start
class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
       int n = values.size();
       int dp[n][n];
       memset(dp, 0, sizeof(dp));
       function<int(int, int) > calculateMinScore = [&](int start, int end) {
           if (start + 1 == end) return 0;

           if (dp[start][end] != 0) return dp[start][end];
           int ans = INT_MAX;
           for (int k = start + 1; k < end; ++k) {
               ans = min(ans, calculateMinScore(start, k) + calculateMinScore(k, end) + values[start] * values[k] * values[end]);
           }
           return dp[start][end] = ans;
       };
       return calculateMinScore(0, n - 1);
    }
};
// @lc code=end

