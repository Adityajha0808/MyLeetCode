class Solution {
public:
    int minimumTotal(vector<vector<int>>& a) {
        int n = a.size();
        vector<int> dp(a[n-1]);
        for(int i=n-2; i>=0; --i) {
            for(int j=0; j<=i; ++j) {
                dp[j] = min(dp[j], dp[j+1]) + a[i][j];
            }
        }
        return dp[0];
    }
};