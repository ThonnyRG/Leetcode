/*
 * @lc app=leetcode id=1578 lang=cpp
 *
 * [1578] Minimum Time to Make Rope Colorful
 */

// @lc code=start
class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        int maxTime = 0;
        int lastInd = 0;
        int  n = neededTime.size();

        for (int i = 1; i < n; i++)
        {
            if (colors[i] != colors[lastInd])
            {
                lastInd = i;
            }else{
                if (neededTime[i] < neededTime[lastInd])
                {
                    maxTime += neededTime[i];
                }else{
                    maxTime += neededTime[lastInd];
                    lastInd = i;
                }
                
            }
            
        }
        return maxTime;
    }
};
// @lc code=end
