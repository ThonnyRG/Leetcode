/*
 * @lc app=leetcode id=3228 lang=cpp
 *
 * [3228] Maximum Number of Operations to Move Ones to the End
 */

// @lc code=start
class Solution {
public:
    static int maxOperations(string& s) {
        int cnt = 0, n = s.size(), cnt1 = (s[0] == '1');
        for (int i = 1; i < n; i++) {
            if (s[i] == '1')
                cnt1++;
            else if (s[i - 1] == '1')
                cnt += cnt1;
        }
        return cnt;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
// @lc code=end

