/*
 * @lc app=leetcode id=2438 lang=cpp
 *
 * [2438] Range Product Queries of Powers
 */

// @lc code=start
class Solution {
public:
    int MOD = 1000000007; 
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powersOfTwo;

        while(n > 0){
            int largestPowerOfTwo = n & -n;
            powersOfTwo.emplace_back(largestPowerOfTwo);
            n -= largestPowerOfTwo;

        }
        vector<int> answer;

        for (auto& query : queries)
        {
            int start = query[0], end = query[1];
            long long product = 1;

            for (int i = start; i <= end; i++)
            {
                product = (product * powersOfTwo[i]) % MOD;
            }
            answer.emplace_back(static_cast<int>(product));
        }
        return answer;
    }
};
// @lc code=end

