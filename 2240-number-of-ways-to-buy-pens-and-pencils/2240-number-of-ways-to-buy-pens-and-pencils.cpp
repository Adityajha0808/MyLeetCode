using ll = long long;
class Solution {
public:
    ll waysToBuyPensPencils(int n, int c1, int c2) {
        vector<ll> dp(n+1,0);
        dp[0] = 1;
        for(int i=c1; i<=n; ++i) dp[i] += dp[i - c1];
        for(int i=c2; i<=n; ++i) dp[i] += dp[i - c2];
        return accumulate(dp.begin(), dp.end(), 0LL);
    }
};