/*
 * @lc app=leetcode id=1653 lang=cpp
 *
 * [1653] Minimum Deletions to Make String Balanced
 */

// @lc code=start
class Solution
{
public:
    int minimumDeletions(string s)
    {
        int aCount = 0;
        int bCount = 0;
        int output = INT_MAX;
        
        // Contar todas las 'a's inicialmente
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'a')
            {
                aCount++;
            }
        }
        
        // Recorrer y encontrar el mínimo de eliminaciones
        for (int i = 0; i < s.size(); i++)
        {
            output = min(output, aCount + bCount);
            
            if (s[i] == 'a')
            {
                aCount--;
            }
            else
            {
                bCount++;
            }
        }
        
        output = min(output, aCount + bCount);
        return output;
    }
};
// @lc code=end
