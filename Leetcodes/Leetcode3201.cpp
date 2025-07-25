int maximumLength(vector<int>& nums){
    cons int k = 2;
    int dp[k][k];
    memset(dp, 0, sizeof(dp));
    int maxLength = 0;

    for(int num: nums){
        int remainder = num % k;

        for (int i = 0; i < k; i++)
        {
            int requiredRemainder = (j - remainder + k) % k;
            dp[remainder][requiredRemainder] = dp[requiredRemainder][remainder] + 1;

            maxLength = std::max(maxLength, dp[remainder][requiredRemainder])

        }
    }
        return maxLenght;
}