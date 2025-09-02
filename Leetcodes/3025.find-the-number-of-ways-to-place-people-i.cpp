/*
 * @lc app=leetcode id=3025 lang=cpp
 *
 * [3025] Find the Number of Ways to Place People I
 */

// @lc code=start
class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {

        int n = points.size();
        int ans = 0;

        ranges::sort(points, ranges::less{}, [](const vector<int>& point){

            const int x = point[0];
            const int y = point[1];
            return pair<int, int>{x, -y};
        });

        for (int i = 0; i < n; ++i){
            int maxY = INT_MIN;
            for (int j = i + 1;  j < n;  ++j)
                if(points[i][1] >= points[j][1] && points[j][1] > maxY){
                    ++ans;
                    maxY = points[j][1];
                }
        }
        return ans;   
    }
};
// @lc code=end

