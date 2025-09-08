/*
 * @lc app=leetcode id=1317 lang=cpp
 *
 * [1317] Convert Integer to the Sum of Two No-Zero Integers
 */

// @lc code=start
class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; ;++i)
        {
            int j = n - i;
            string combined = to_string(i) + to_string(j);

            if (combined.find('0') == string::npos)
            {
                return{i, j};
            }
            

        }
        
    }
};
// @lc code=end

