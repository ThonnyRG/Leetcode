/*
 * @lc app=leetcode id=190 lang=cpp
 *
 * [190] Reverse Bits
 */

// @lc code=start
class Solution {
public:
    int reverseBits(int n) {
       int ans = 0;
        for (int i = 0; i < 32; i++)
        {
            if ((n & (1 << i)) != 0)
            {
                ans |= (1 << (31 - i));
            }
            
        }
        return ans;

    }
};
// @lc code=end

