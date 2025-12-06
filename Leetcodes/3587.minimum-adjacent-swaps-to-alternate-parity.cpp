/*
 * @lc app=leetcode id=3587 lang=cpp
 *
 * [3587] Minimum Adjacent Swaps to Alternate Parity
 */

// @lc code=start
class Solution
{
public:
    int minSwaps(vector<int> &nums)
    {
        vector<int> positions[2];
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            positions[nums[i] & 1].push_back(i);
        }

        if (abs(int(positions[0].size() - positions[1].size())) > 1)
        {
            return -1;
        }

        auto calculateSwaps = [&](int startingParity)
        {
            int totalSwaps = 0;
            for (int i = 0; i < n; i += 2)
            {
                totalSwaps += abs(positions[startingParity][i / 2] - i);
            }
            return totalSwaps;
        };
        if (positions[0].size() > positions[1].size())
        {
            return calculateSwaps(0);
        }
        if (positions[0].size() < positions[1].size())
        {
            return calculateSwaps(1);
        }
        return min(calculateSwaps(0), calculateSwaps(1));
    }
};
// @lc code=end
