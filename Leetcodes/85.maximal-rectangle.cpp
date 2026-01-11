/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 */

// @lc code=start
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> heights(n, 0);
        vector<int> leftBoundaries(n, 0);
        vector<int> rightBoundaries(n, n);
        
        int maxRectangle = 0;
        
        for (int i = 0; i < m; i++) {
            int left = 0;
            int right = n;
            
            updateHeightsAndLeftBoundaries(matrix[i], heights, leftBoundaries, left);
            
            updateRightBoundaries(matrix[i], rightBoundaries, right);
            
            maxRectangle = calculateMaxRectangle(heights, leftBoundaries, rightBoundaries, maxRectangle);
        }
        
        return maxRectangle;
    }
    
private:
    void updateHeightsAndLeftBoundaries(vector<char>& row, vector<int>& heights, 
                                        vector<int>& leftBoundaries, int left) {
        for (int j = 0; j < heights.size(); j++) {
            if (row[j] == '1') {
                heights[j]++;
                leftBoundaries[j] = max(leftBoundaries[j], left);
            } else {
                heights[j] = 0;
                leftBoundaries[j] = 0;
                left = j + 1;
            }
        }
    }
    
    void updateRightBoundaries(vector<char>& row, vector<int>& rightBoundaries, int right) {
        for (int j = rightBoundaries.size() - 1; j >= 0; j--) {
            if (row[j] == '1') {
                rightBoundaries[j] = min(rightBoundaries[j], right);
            } else {
                rightBoundaries[j] = right;
                right = j;
            }
        }
    }
    
    int calculateMaxRectangle(vector<int>& heights, vector<int>& leftBoundaries, 
                             vector<int>& rightBoundaries, int maxRectangle) {
        for (int j = 0; j < heights.size(); j++) {
            int width = rightBoundaries[j] - leftBoundaries[j];
            int area = heights[j] * width;
            maxRectangle = max(maxRectangle, area);
        }
        return maxRectangle;
    }
};
// @lc code=end

