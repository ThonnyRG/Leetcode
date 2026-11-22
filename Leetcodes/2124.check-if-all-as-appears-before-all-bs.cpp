/*
 * @lc app=leetcode id=2124 lang=cpp
 *
 * [2124] Check if All A's Appears Before All B's
 */

// @lc code=start
class Solution {
public:
    bool checkString(string s) {
        string t = "ba";
        return s.find(t) == string::npos;

    }
};
// @lc code=end

