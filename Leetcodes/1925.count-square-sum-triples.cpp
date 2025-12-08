/*
 * @lc app=leetcode id=1925 lang=cpp
 *
 * [1925] Count Square Sum Triples
 */

// @lc code=start
class Solution
{
public:
    int countTriples(int n)
    {
        int count = 0;
        for (int i = 1; i < n; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                int sumOfSquares = i * i + j * j;
                int C = static_cast<int>(sqrt(sumOfSquares));

                if (C <= n && C * C == sumOfSquares)
                {
                    ++count;
                }
            }
        }
        return count;
    }
};
// @lc code=end
