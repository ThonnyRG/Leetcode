/*
 * @lc app=leetcode id=401 lang=cpp
 *
 * [401] Binary Watch
 */

// @lc code=start
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result; 

        for (int hour = 0; hour < 12; hour++)
        {
            for (int minute = 0; minute < 60; minute++)
            {
                int bits_on = __builtin_popcount(hour) + __builtin_popcount(minute);
                if (bits_on == turnedOn)
                {
                    result.push_back(format("{}:{:02d}", hour, minute));
                }
                
            }
            
        }
        
                return result;
    }
};
// @lc code=end

