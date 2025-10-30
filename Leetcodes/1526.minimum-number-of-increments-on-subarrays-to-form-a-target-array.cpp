/*
 * @lc app=leetcode id=1526 lang=cpp
 *
 * [1526] Minimum Number of Increments on Subarrays to Form a Target Array
 */

// @lc code=start
class Solution {
public:
    static int minNumberOperations(vector<int>& target) {
        adjacent_difference(target.begin(), target.end(), target.begin());
        return accumulate(target.begin(), target.end(), 0,
        [](int sum, int x){ return sum+=max(0,x);});
    }
};
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
// @lc code=end

