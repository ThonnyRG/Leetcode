/*
 * @lc app=leetcode id=2141 lang=cpp
 *
 * [2141] Maximum Running Time of N Computers
 */

// @lc code=start
class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sumPower = 0;
        for (int battery : batteries) {
            sumPower += battery;
        }
        
        long long left = 1;
        long long right = sumPower / n;
        
        while (left < right) {
            long long time = (left + right + 1) / 2;
            
            if (check(batteries, n, time)) {
                left = time;
            } else {
                right = time - 1;
            }
        }
        
        return left;
    }
    
private:
    bool check(const vector<int>& B, int n, long long time) {
        long long total_power = 0;
        for (int battery : B) {
            total_power += min((long long)battery, time);
        }
        
        return total_power >= (long long)n * time;
    }
};
// @lc code=end

