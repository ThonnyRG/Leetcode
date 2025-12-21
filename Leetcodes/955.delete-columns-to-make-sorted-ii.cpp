/*
 * @lc app=leetcode id=955 lang=cpp
 *
 * [955] Delete Columns to Make Sorted II
 */

// @lc code=start
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
       if (strs.empty() || strs.size() <= 1)
       {
        return 0;
       }
       
        int numStrings = strs.size();       
        int stringLength = strs[0].length();
        int deletedColumns = 0;       

        vector<bool> sorted(numStrings - 1, false);

        for (int i = 0; i < stringLength; i++)
        {
            bool ShouldDelete = false;

            for (int j = 0; j < numStrings - 1; j++)
            {
                if (!sorted[j] && strs[j][i] > strs[j + 1][i])
                {
                    ShouldDelete = true;
                    break;
                }
                
            }

            if (ShouldDelete)
            {
                deletedColumns++;
                continue;
            }

            for (int k = 0; k < numStrings - 1; k++)
            {
                if (strs[k][i] < strs[k + 1][i])
                {
                    sorted[k] = true;
                }
                
            }
            
            
            
        }
        
        return deletedColumns;

    }
};
// @lc code=end

