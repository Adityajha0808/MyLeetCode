class Solution {
public:
    int coinChange(vector<int>& a, int k) {
        int n = a.size();
        sort(a.begin(), a.end());
        vector<int> dp(10001,INT_MAX);
        dp[0] = 0;
        for(int i=0; i<=10000; ++i)
            for(int j=0; j<n; ++j)
                if(a[j] <= i and dp[i - a[j]] != INT_MAX)
                    dp[i] = min(dp[i], dp[i - a[j]] + 1);
        return (dp[k] == INT_MAX ? -1 : dp[k]);
    }
};