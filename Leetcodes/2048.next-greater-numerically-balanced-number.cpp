/*
 * @lc app=leetcode id=2048 lang=cpp
 *
 * [2048] Next Greater Numerically Balanced Number
 */

// @lc code=start
class Solution {
private:
    int base[13] = {1, 22, 122, 333, 1333, 4444, 14444, 22333, 55555, 122333, 155555, 224444, 666666};
public:
    int nextBeautifulNumber(int n) {
        string s = to_string(n);
        int res = 1224444, slen = s.length();
        for (int i = 0; i < 13; ++i) {
            string ss = to_string(base[i]);
            int sslen = ss.length();
            if (sslen < slen) continue;
            if (sslen > slen) res = min(res, base[i]);
            else {
                do {
                    if (ss > s) res = min(res, stoi(ss));
                } while(next_permutation(begin(ss), end(ss)));
            }
        }
        return res;
    }
};
// @lc code=end

