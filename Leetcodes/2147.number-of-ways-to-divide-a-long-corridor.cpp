/*
 * @lc app=leetcode id=2147 lang=cpp
 *
 * [2147] Number of Ways to Divide a Long Corridor
 */

// @lc code=start
class Solution
{
public:
    int numberOfWays(string corridor)
    {
        int x = 1;
        int y = 0;
        int z = 0;
        int mod = (int)1e9 + 7;
        int n = corridor.size();
        for (int i = 0; i < n; ++i)
        
            if (corridor.at(i) == 'S')
            {
                x = (x + z) % mod;
                z = y;
                y = x;
                x = 0;
            }
            else
            {
                x = (x + z) % mod;
            }
            return z;
    }
};
// @lc code=end
