/*
 * @lc app=leetcode id=3000 lang=cpp
 *
 * [3000] Maximum Area of Longest Diagonal Rectangle
 */

// @lc code=start
class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
       int maxArea = 0;
       int maxDIagonalSq = 0;

       for (auto& dimension : dimensions)
       {
        int length = dimension[0];
        int width = dimension[1];  
        int diagonalSQ = length * length + width * width;
    
        if (maxDIagonalSq < diagonalSQ)
        {
            maxDIagonalSq = diagonalSQ;
            maxArea = length * width;
        }else if (maxDIagonalSq == diagonalSQ)
        {
            maxArea = max(maxArea, length * width);
        }
   
        

       }
            return maxArea;
    }
};
// @lc code=end

