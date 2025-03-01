class Solution {
    public:
        vector<int> applyOperations(vector<int>& nums) {
            int size = nums.size();
            for(int i = 1; i < size; ++i){
                if(nums[i]==nums[i-1]){
                    nums[i-1]*=2;
                    nums[i] = 0;
                }
            }
            int index = 0;
            for(int i = 0 ;i < size;++i){
                if(nums[i]){
                    nums[index++] = nums[i];
                }
            }
            while(index<size){
                nums[index++]=0;
            }
    
            return nums;
        }
    };