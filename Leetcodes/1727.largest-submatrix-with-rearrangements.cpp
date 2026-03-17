/*
 * @lc app=leetcode id=1727 lang=cpp
 *
 * [1727] Largest Submatrix With Rearrangements
 */

// @lc code=start
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        for (int i = 1; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 1) {
                    matrix[i][j] = matrix[i - 1][j] + 1;
                }
            }
        }

        int count = 0;

        for (int i = 0; i < rows; i++) {
            sort(matrix[i].begin(), matrix[i].end());

            for (int j = 1; j <= cols; j++) {
                count = max(count, j * matrix[i][cols - j]);
            }
        }

        return count;
    }
};
// @lc code=end

