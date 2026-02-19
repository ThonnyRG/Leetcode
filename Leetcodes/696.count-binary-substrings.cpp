/*
 * @lc app=leetcode id=696 lang=cpp
 *
 * [696] Count Binary Substrings
 */

// @lc code=start
class Solution {
public:
    int countBinarySubstrings(string s) {
        int prev = 0, curr = 1, res = 0, n = s.length();
        for (int i = 1; i < n; ++i) {
            if (s[i] == s[i - 1]) ++curr;
            else {
                res += min(prev, curr);
                prev = curr;
                curr = 1;
            }
        }
        res += min(prev, curr);
        return res;
    }
};
// @lc code=end

