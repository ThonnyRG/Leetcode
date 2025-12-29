/*
 * @lc app=leetcode id=756 lang=cpp
 *
 * [756] Pyramid Transition Matrix
 */

// @lc code=start
class Solution {
public:
    bool helper(int index, string nextBottom, string bottom,
                unordered_map<string, vector<char>> &mp,
                unordered_map<string, bool> &memo) {
        if (bottom.size() == 1) return true;

        if (index == bottom.size() - 1) {
            if (memo.find(nextBottom) != memo.end()) {
                return memo[nextBottom];
            }
            bool res = helper(0, "", nextBottom, mp, memo);
            memo[nextBottom] = res;
            return res;
        }

        string temp = bottom.substr(index, 2);
        for (char ch : mp[temp]) {
            if (helper(index + 1, nextBottom + ch, bottom, mp, memo)) {
                return true;
            }
        }
        return false;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        unordered_map<string, vector<char>> mp;
        unordered_map<string, bool> memo;

        for (string &str : allowed) {
            string key = str.substr(0, 2);
            mp[key].push_back(str[2]);
        }

        return helper(0, "", bottom, mp, memo);
    }
};
// @lc code=end

