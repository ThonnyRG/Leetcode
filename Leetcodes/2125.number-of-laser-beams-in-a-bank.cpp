/*
 * @lc app=leetcode id=2125 lang=cpp
 *
 * [2125] Number of Laser Beams in a Bank
 */

// @lc code=start
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0;
        int prevArrLaserCount = 0;
        
        for(const string& i : bank) {
            int curArrLaserCount = 0;
            
            for(char j : i) {
                if(j == '1') {
                    curArrLaserCount++;
                }
            }
            
            if(curArrLaserCount > 0) {
                ans += prevArrLaserCount * curArrLaserCount;
                prevArrLaserCount = curArrLaserCount;
            }
        }
        
        return ans;
    }
};

// @lc code=end
