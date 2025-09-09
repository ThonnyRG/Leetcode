/*
 * @lc app=leetcode id=2327 lang=cpp
 *
 * [2327] Number of People Aware of a Secret
 */

// @lc code=start
using ll = long long;
const int MOD = 1e9 + 7;

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
       int maxDays = (n << 1) + 10;
       vector<ll> deltaKnowers(maxDays);
       vector<ll> newSpreaders(maxDays);;

       newSpreaders[1] = 1;

       for (int day = 1; day <= n; day++)
       {
        if (!newSpreaders[day]) continue; 
        deltaKnowers[day] = (deltaKnowers[day] + newSpreaders[day]) % MOD;
        
        deltaKnowers[day + forget] = (deltaKnowers[day + forget] - newSpreaders[day] + MOD) % MOD;
        int startSpreadingDay = day + delay;
        while(startSpreadingDay < day + forget){
            newSpreaders[startSpreadingDay] = (newSpreaders[startSpreadingDay] + newSpreaders[day] % MOD);
            ++startSpreadingDay;

        }


       }       
        int totalPeopleKnowing = 0;
        for (int day = 1; day <= n; day++)
        {
            totalPeopleKnowing = (totalPeopleKnowing + deltaKnowers[day]) % MOD;
        }
        
               return totalPeopleKnowing;

    }
};
// @lc code=end

