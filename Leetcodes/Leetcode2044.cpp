class Solution {
public:
    void solve(vector<int>& nums, int i, int& maxi, int& count, vector<int>& subset){
        //base case
        if(i >= nums.size()){
            int orSum = 0;
            for(int ind = 0; ind < subset.size(); ind++){
                orSum = orSum | subset[ind];
            }
            if(orSum > maxi){
                maxi = orSum;
                count = 0;
            }
            if(orSum == maxi){
                maxi = orSum;
                count++;
            }
            return;
        }

        //inlcude wala case
        subset.push_back(nums[i]);
        solve(nums, i+1, maxi, count, subset);
        subset.pop_back();

        //exclude wala case
        solve(nums, i+1, maxi, count, subset);

    }


    int countMaxOrSubsets(vector<int>& nums) {
        vector<int> subset;
        int i = 0;
        int maxi = INT_MIN;
        int count = 0;
        solve(nums, i, maxi, count, subset);
        return count;
    }
};