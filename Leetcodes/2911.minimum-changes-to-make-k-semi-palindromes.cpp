/*
 * @lc app=leetcode id=2911 lang=cpp
 *
 * [2911] Minimum Changes to Make K Semi-palindromes
 */

// @lc code=start
class Solution {
public:
    int dp[210][110];  // A 2D array to store dynamic programming values.
    vector<int> fac[210];  // A vector of vectors to store factors of string lengths.

    // Function to calculate the number of changes needed to make a string palindrome.
    int num(string st) {
        int n = st.length();
        int ans = 1e9;  // Initialize ans with a large value.

        // Iterate through all factors of the string length.
        for (auto it : fac[st.length()]) {
            int nu = n / it;
            int cur = 0;

            // Compare characters in the string to make it a palindrome.
            for (int i = 0; i < nu / 2; i++) {
                int i2 = nu - i - 1;
                for (int j = 0; j < it; j++)
                    if (st[i * it + j] != st[i2 * it + j])
                        cur++;
            }

            ans = min(ans, cur);  // Update ans with the minimum changes needed.
        }
        return ans;
    }

    // Main function to calculate the minimum changes needed.
    int minimumChanges(string st, int k) {
        int n = st.length();

        // Precompute factors for string lengths.
        for (int i = 2; i <= n; i++)
            for (int j = 1; j < i; j++)
                if (i % j == 0)
                    fac[i].push_back(j);

        // Initialize the dp array with a large value.
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= k; j++)
                dp[i][j] = 1e9;

        dp[0][0] = 0;  // Base case: no changes needed for an empty string.

        // Dynamic programming to find the minimum changes needed.
        for (int i = 0; i < n; i++)
            for (int j = 0; j <= i; j++) {
                string cur = st.substr(j, i - j + 1);
                int add = num(cur);  // Calculate changes needed for the current substring.

                // Update dp values for different values of k.
                for (int l = 0; l < k; l++)
                    dp[i + 1][l + 1] = min(dp[i + 1][l + 1], dp[j][l] + add);
            }

        return dp[n][k];  // Return the minimum changes needed for the entire string.
    }
};

// @lc code=end

