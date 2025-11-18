/*
 * @lc app=leetcode id=717 lang=cpp
 *
 * [717] 1-bit and 2-bit Characters
 */

// @lc code=start
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0;
       int n = bits.size();
        while (i < n - 1)
        {
            i += bits[i] + 1;
        }
        return i == n - 1;
        
    }
};
// @lc code=end

