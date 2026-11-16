/*
 * @lc app=leetcode id=2243 lang=cpp
 *
 * [2243] Calculate Digit Sum of a String
 */

// @lc code=start
class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size() > k) {
            string temp = "";
            for(int i = 0; i < s.size(); i += k) {
                int sum = 0;
                for(int j = i; j < min(i + k, (int)s.size()); j++) {
                    sum += s[j] - '0';
                }
                temp += to_string(sum);
            }
            s = temp;
        }
        return s;
    }
};
// @lc code=end

