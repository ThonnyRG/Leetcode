/*
 * @lc app=leetcode id=3453 lang=cpp
 *
 * [3453] Separate Squares I
 */

// @lc code=start
class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double maxy = 0, totalarea = 0;
        for (auto& sq : squares) {
            int y = sq[1], l = sq[2];
            totalarea += (double)l * l;
            maxy = max(maxy, (double)(y + l));
        }

        auto check = [&](double limity) -> bool {
            double area = 0;
            for (auto& sq : squares) {
                int y = sq[1], l = sq[2];
                if (y < limity) {
                    area += l * min(limity - y, (double)l);
                }
            }
            return area >= totalarea / 2;
        };

        double lo = 0, hi = maxy;
        double eps = 1e-5;
        while (abs(hi - lo) > eps) {
            double mid = (hi + lo) / 2;
            if (check(mid)) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
        return hi;
    }
};
// @lc code=end

