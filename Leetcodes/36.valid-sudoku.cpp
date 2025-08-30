/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::vector<std::vector<bool>> rowCheck(9, std::vector<bool>(9, false));     
        std::vector<std::vector<bool>> colCheck(9, std::vector<bool>(9,false));             
        std::vector<std::vector<bool>> subBoxCheck(9, std::vector<bool>(9, false));  
        
        
        for (int row = 0; row < 9; ++row)
        {
            for (int col = 0; col < 9; ++col)
            {
                char currentChar = board[row][col];

                if (currentChar == '.') continue;

                int num = currentChar - '0' - 1;

                int subBoxIndex = (row / 3) * 3 + (col / 3);

                if (rowCheck[row][num] || colCheck[col][num] || subBoxCheck[subBoxIndex][num])
                {
                    return false;
                }
                rowCheck[row][num] = true;
                colCheck[col][num] = true;
                subBoxCheck[subBoxIndex][num] = true;
            }
            
        }
        return true;

    }
};
// @lc code=end

