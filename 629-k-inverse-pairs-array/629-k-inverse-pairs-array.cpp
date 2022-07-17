class Solution {
public:
    int mod = 1000000007;
    int kInversePairs(int n, int k) {
        // int dp[1001][1001] = {1};
        // for(int i=1; i<=n; ++i)
        //     for(int j=0; j<=k; ++j)
        //         for(int k=0; k<= min(i, j-1); ++k) 
        //             dp[i][j] = (dp[i][j] + dp[k-1][j-k]) % mod;
        // return dp[n][k];
        int dp[1001][1001] = { 1 };
    for (int N = 1; N <= n; ++N)
        for (int K = 0; K <= k; ++K)
            for (int i = 0; i <= min(K, N - 1); ++i) 
                dp[N][K] = (dp[N][K] + dp[N - 1][K - i]) % 1000000007;
    return dp[n][k];
    }
};