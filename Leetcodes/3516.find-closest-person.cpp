/*
 * @lc app=leetcode id=3516 lang=cpp
 *
 * [3516] Find Closest Person
 */

// @lc code=start
class Solution {
public:
    int findClosest(int x, int y, int z) {
        const int xz = abs(x - z);
        const int yz = abs(y - z);
        if (xz == yz)
        return 0;
        return xz < yz ? 1 : 2;
        

    }
};
// @lc code=end

