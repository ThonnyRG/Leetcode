class Solution {
    private int mod= 1000000007;
    int dp[][][] = new int[100002][2][3];
    public int solve(int ind,int n,int cnt_abs,int cnt_late)
    {
        if(ind >= n)
        return 1;
        if(dp[ind][cnt_abs][cnt_late]!=-1)
        return dp[ind][cnt_abs][cnt_late];
            int abs= cnt_abs==0?solve(ind+1,n,1,0):0;
            int pre = solve(ind+1,n,cnt_abs,0);
            int late=0;
            if(cnt_late!=2)
            late=solve(ind+1,n,cnt_abs,cnt_late+1);
            return dp[ind][cnt_abs][cnt_late]=((pre+late)%mod+abs)%mod;
    }
    public int checkRecord(int n) {
         for (int i = 0; i < 100002; i++) {
             for (int j = 0; j < 2; j++) {
                 for (int k = 0; k < 3; k++) {
                     dp[i][j][k] = -1;
        }
    }
}
              return solve(0,n,0,0);
        
    }
}