class Solution {
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
            int n = grid.size();
            int m = grid[0].size();
            vector<int>ans(m*n+1,0);
    
            for(int i=0;i<n;i++){
                for(int j =0;j<m;j++){
                    ans[grid[i][j]]++;
                }
            }
            int missing =0,rep =0;
            for(int i=0;i<ans.size();i++){
                if(ans[i]==0)missing = i;
                if(ans[i]==2)rep = i;
            }
    
            return {rep,missing};
        }
    };