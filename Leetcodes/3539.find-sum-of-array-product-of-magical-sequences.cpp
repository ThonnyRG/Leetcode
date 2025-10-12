/*
 * @lc app=leetcode id=3539 lang=cpp
 *
 * [3539] Find Sum of Array Product of Magical Sequences
 */

// @lc code=start
using namespace std;
static const int MOD = 1000000007;
static const int MAXN = 50;
static const int MAXM = 30;
static const int MAXK = 30;

// Fast exponentiation
inline int modexp(long long a, int e) {
    long long r = 1;
    while (e) {
        if (e & 1) r = (r * a) % MOD;
        a = (a * a) % MOD;
        e >>= 1;
    }
    return int(r);
}

class Solution {
public:
    int magicalSum(int M, int K, vector<int>& nums) {
        static int fac[MAXM+1], inv_fac[MAXM+1];
        fac[0] = 1;
        for (int i = 1; i <= M; i++) fac[i] = int((long long)fac[i-1] * i % MOD);
        for (int i = 0; i <= M; i++) inv_fac[i] = modexp(fac[i], MOD-2);

        int n = nums.size();

        static int pow_nums[MAXN][MAXM+1];
        for (int j = 0; j < n; j++) {
            pow_nums[j][0] = 1;
            for (int c = 1; c <= M; c++)
                pow_nums[j][c] = int((long long)pow_nums[j][c-1] * nums[j] % MOD);
        }

        static int dp[2][MAXM+1][MAXM+1][MAXK+1];
        int cur = 0, nxt = 1;
        memset(dp[cur], 0, sizeof(dp[cur]));
        dp[cur][0][0][0] = 1;

        for (int j = 0; j < n; j++) {
            memset(dp[nxt], 0, sizeof(dp[nxt]));

            for (int m = 0; m <= M; m++) {
                for (int carry = 0; carry <= M; carry++) {
                    for (int kcnt = 0; kcnt <= K; kcnt++) {
                        int val = dp[cur][m][carry][kcnt];
                        if (!val) continue;
                        for (int c = 0; c + m <= M; c++) {
                            int m2 = m + c;
                            int s  = carry + c;
                            int b  = s & 1;
                            int k2 = kcnt + b;
                            if (k2 > K) break;  
                            int carry2 = s >> 1;

                            long long add = (long long)val * pow_nums[j][c] % MOD;
                            add = (add * inv_fac[c]) % MOD;

                            int &dest = dp[nxt][m2][carry2][k2];
                            dest = dest + int(add);
                            if (dest >= MOD) dest -= MOD;
                        }
                    }
                }
            }
            swap(cur, nxt);
        }

        long long total = 0;
        for (int carry = 0; carry <= M; carry++) {
            int pc = __builtin_popcount(carry);
            for (int kcnt = 0; kcnt + pc <= K; kcnt++) {
                if (kcnt + pc == K) {
                    total += dp[cur][M][carry][kcnt];
                }
            }
        }
        total %= MOD;
        return int(total * fac[M] % MOD);
    }
};
// @lc code=end

