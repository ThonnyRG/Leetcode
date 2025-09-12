/*
 * @lc app=leetcode id=3227 lang=cpp
 *
 * [3227] Vowels Game in a String
 */

// @lc code=start
class Solution {
public:
    bool doesAliceWin(string s) {
        for (int i = 0; i < s.size(); i++)
            if ((0x104111 >> (s[i] - 97)) & 1)
                return 1;                                
        return 0;
    }
};
// @lc code=end

