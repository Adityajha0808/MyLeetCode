class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& a) {
        int n = a.size(), res = 0;
        vector<int> dp(n+1, 0);
        dp[1] = a[0];
        for(int i=2; i<=n; ++i)
            dp[i] = dp[i-1] + a[i-1];
        for(int i=0; i<n; ++i) {
            for(int j=i; j<n; ++j) {
                if((j-i)%2 == 0) {
                    res += dp[j+1] - dp[i];
                }
            }
        }
        return res;
    }
};