class Solution {
    public int minHeightShelves(int[][] books, int shelfWidth) {
        int n = books.length;
        int[] dp = new int[n+1];
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            dp[i] = books[i - 1][1] + dp[i - 1];
            int height = books[i - 1][1];
            int width = books[i - 1][0];
            
            for (int j = i - 1; j > 0; j--) { 
                width += books[j - 1][0];
                if (width > shelfWidth) {
                    break; 
                }
                height = Math.max(height, books[j - 1][1]);
                dp[i] = Math.min(dp[i], height + dp[j - 1]);
            }
        }
        return dp[n];
    }
}
