/*
 * @lc app=leetcode id=2211 lang=cpp
 *
 * [2211] Count Collisions on a Road
 */

// @lc code=start
class Solution {
public:
    int countCollisions(string directions) {
       int n = directions.size();

       int leftBoundary = 0;
       while(leftBoundary < n && directions[leftBoundary] == 'L'){
            ++leftBoundary;
       }

       int rightBoundary = n - 1;
       while (rightBoundary >= 0 && directions[rightBoundary] == 'R')
       {
        --rightBoundary;
       }

       int totalCarsInRange = rightBoundary - leftBoundary + 1;
       int stationaryCars = count(directions.begin() + leftBoundary, directions.begin() + rightBoundary + 1, 'S');

       return totalCarsInRange - stationaryCars;
       
    }
};
// @lc code=end

