/*
 * @lc app=leetcode id=1582 lang=cpp
 *
 * [1582] Special Positions in a Binary Matrix
 */

// @lc code=start
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
       int ans = 0;
       int m = mat.size();
        int n = mat[0].size();

        for (int row = 0; row < m; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (mat[row][col] == 1)
                {
                bool good = true;
                for (int r = 0; r < m; r++)
                {
                    if (r != row && mat[r][col] == 1)
                    {
                        good = false;
                        break; 
                    }
                    
                }
                if (good)
                {
                    for (int c = 0; c < n; c++)
                    {
                        if (c != col && mat[row][c] == 1)
                        {
                            good = false;
                            break;
                        }
                        
                    }
                    
                }
                
                if (good) ans++;
            }
            
        }
    }
        return ans;
    }
};
// @lc code=end

