class Solution {
    public:
        int size;
        string result;
        bool solve(unordered_map<string,bool> &maps, string &current, int index){
            if(index>=size){
                if(!maps[current]){
                    result = current;
                    return true;
                }
                return false;
            }
            for(auto &a : {'0','1'}){
                current[index] = a;
                if(solve(maps,current,index+1)){
                    return true;
                }
            }
            return false;
        }
        string findDifferentBinaryString(vector<string>& nums) {
            size = nums[0].size();
            unordered_map<string,bool> maps;
            for(auto &x : nums){
                maps[x] = true;
            }
            solve(maps,nums[0],0);
            return result;
        }
    };