/*
 * @lc app=leetcode id=3229 lang=cpp
 *
 * [3229] Minimum Operations to Make Array Equal to Target
 */
class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        if(workerTimes.size()==1){
            return workerTimes[0]* (long long)mountainHeight*(mountainHeight+1)/2;
        }
        priority_queue<pair<long long ,pair<long long ,long long >> , 
         vector<pair<long long ,pair<long long ,long long >>> ,
         greater<pair<long long ,pair<long long ,long long >>>>qu;

         for(int i=0;i<workerTimes.size();i++){
            qu.push({workerTimes[i],{workerTimes[i],1}});
         }

         int ans=0;

         for(int i=0;i<mountainHeight;i++){
            int time=qu.top().first;
            int original=qu.top().second.first;
            int height_reduced=qu.top().second.second;
            qu.pop();

            ans=time;
            qu.push({time+(long long)original*(height_reduced+1) ,{original,height_reduced+1}});
         }

         return ans;

    }
};
// @lc code=end

