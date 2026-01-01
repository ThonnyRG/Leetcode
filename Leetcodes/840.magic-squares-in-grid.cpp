/*
 * @lc app=leetcode id=840 lang=cpp
 *
 * [840] Magic Squares In Grid
 */

// @lc code=start
class Solution {
private:
    static int magic(int a, int b, int c, int d, int e, int f, int g, int h, int i) {
        unordered_set<int> s1 = {a, b, c, d, e, f, g, h, i};
        unordered_set<int> s2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        
        if (s1 == s2 &&
            (a + b + c) == 15 &&
            (d + e + f) == 15 &&
            (g + h + i) == 15 &&
            (a + d + g) == 15 &&
            (b + e + h) == 15 &&
            (c + f + i) == 15 &&
            (a + e + i) == 15 &&
            (c + e + g) == 15) {
            return 1;
        }
        return 0;
    }
    
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int answer = 0;
        int Nrows = grid.size();
        int Ncolumns = grid[0].size();
        
        if (Nrows >= 3 && Ncolumns >= 3) {
            for (int i = 0; i <= Nrows - 3; i++) {
                for (int j = 0; j <= Ncolumns - 3; j++) {
                    if (grid[i + 1][j + 1] != 5) continue;
                    
                    if (magic(grid[i][j], grid[i][j + 1], grid[i][j + 2],
                              grid[i + 1][j], grid[i + 1][j + 1], grid[i + 1][j + 2],
                              grid[i + 2][j], grid[i + 2][j + 1], grid[i + 2][j + 2]) != 0) {
                        answer += 1;
                    }
                }
            }
        }
        
        return answer;
    }
};
// @lc code=end

