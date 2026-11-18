/*
 * @lc app=leetcode id=2914 lang=cpp
 *
 * [2914] Minimum Number of Changes to Make Binary String Beautiful
 */

// @lc code=start
class Solution {
public:
    int minChanges(const std::string& s) {
    int count = 0;
    for (int i = 0; i < s.size() - 1; i += 2) {
        if (s[i] != s[i + 1]) {
            count++;
        }
    }
    return count;
}
};
#include <string>

// @lc code=end

