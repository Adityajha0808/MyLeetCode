class Solution {
public:
    int coinChange(vector<int>& a, int k) {
        vector<int> dp(10001,INT_MAX);
        dp[0] = 0;
        for(int i=0; i<=10000; ++i)
            for(auto j: a)
                if(j <= i and dp[i - j] != INT_MAX)
                    dp[i] = min(dp[i], dp[i - j] + 1);
        return (dp[k] == INT_MAX ? -1 : dp[k]);
    }
};