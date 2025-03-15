class Solution {
    public:
        int minCapability(vector<int>& nums, int k) {
           auto isCapable = [&](int capability){
            int count = 0;
            int prevIndex = -2;
            int n = nums.size();

            for (int i = 0; i < n; i++)
            {
                if (nums[i] > capability || i == prevIndex + 1)
                {
                    continue;
                }
                count ++;
                prevIndex = i;
            }
            return count >= k;
           };
           int left = 0;
           int right = *std::max_element(nums.begin(), nums.end());

           while (left < right){
            int mid = (left + right) >> 1;
            if(isCapable(mid)){
                right = mid;
            }else{
                left = mid + 1;
            }

           }
           return left;
        }
    };