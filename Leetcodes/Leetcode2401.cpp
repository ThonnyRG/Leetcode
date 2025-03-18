class Solution {
    public:
        int longestNiceSubarray(vector<int>& nums) {
            int start=0,end=0,n=nums.size(),ans=1;
            long long currAnd=0;
    
            while(end<n){
                while((currAnd & nums[end])!=0){
                    currAnd^=nums[start];
                    start++;
    
                }
                currAnd|=nums[end];
                ans=max(ans,end-start+1);
                end++;
            }
            return ans;
        }
    };