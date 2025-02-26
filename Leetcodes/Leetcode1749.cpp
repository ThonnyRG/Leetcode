class Solution {
    public:
        int maxAbsoluteSum(vector<int>& nums) {
            int n=nums.size();
            int arr[n];
            arr[0]=nums[0];
            int mino=0;int maxo=0;
            if(nums[0]>maxo) maxo=nums[0];
            if(nums[0]<mino) mino=nums[0];
            for(int i=1;i<n;i++){
                arr[i]=arr[i-1]+nums[i];
                if(arr[i]>maxo) maxo=arr[i];
                if(arr[i]<mino) mino=arr[i];
            }
            return abs(maxo-mino);
        }
    };