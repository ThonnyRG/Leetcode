/*
 * @lc app=leetcode id=744 lang=cpp
 *
 * [744] Find Smallest Letter Greater Than Target
 */

// @lc code=start
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char res = letters[0];
        bool flag = false;

        for (char ch : letters) {
            if (!flag) {
                if (ch > target) {
                    res = ch;
                    flag = !flag;
                }
            } else {
                if (ch > target && ch < res) res = ch;
            }
        }

        return res;
    }
};
// @lc code=end

