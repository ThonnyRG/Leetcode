/*
 * @lc app=leetcode id=3494 lang=cpp
 *
 * [3494] Find the Minimum Amount of Time to Brew Potions
 */

// @lc code=start
class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        long long n = skill.size(); 
        long long m = mana.size(); 

        vector<long long> lastpotion(n,0); 
        
        for(long long i=0;i<m;i++){
            vector<long long> prefix(n,0); 
            prefix[0] = skill[0] * mana[i]; 
            for(long long j=1;j<n;j++){
                prefix[j] = prefix[j-1] + skill[j]*mana[i]; 
            }
            long long startTime = lastpotion[0]; 
            for(long long j=1;j<n;j++){
                long long newtime = startTime + prefix[j-1]; 
                if(newtime < lastpotion[j]){
                    long long diff = lastpotion[j] - newtime; 
                    startTime+=diff; 
                }
            }
            vector<long long> newpotion(n); 
            for(long long j=0;j<n;j++){
                newpotion[j] = startTime + skill[j]*mana[i]; 
                startTime = newpotion[j]; 
            }
            lastpotion = newpotion; 
        }
        return lastpotion[n-1]; 
    }
};
// @lc code=end

