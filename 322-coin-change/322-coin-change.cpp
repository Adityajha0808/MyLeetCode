class Solution {
public:
    void func(vector<int>& a, int k, vector<int>& dp) {
        int n = a.size();
        dp[0] = 0;
        for(int i=0; i<=10000; ++i)
            for(int j=0; j<n; ++j)
                if(a[j] <= i and dp[i - a[j]] != INT_MAX)
                    dp[i] = min(dp[i], dp[i - a[j]] + 1);
    }
    int coinChange(vector<int>& a, int k) {
        sort(a.begin(), a.end());
        vector<int> dp(10001,INT_MAX);
        func(a,k,dp);
        return (dp[k] == INT_MAX ? -1 : dp[k]);
    }
};