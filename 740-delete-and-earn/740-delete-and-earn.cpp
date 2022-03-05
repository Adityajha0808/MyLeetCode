class Solution {
public:
    int deleteAndEarn(vector<int>& a) {
        vector<int> dp(10001,0);
        for(auto& i: a) dp[i] += i;
        for(int i=2; i<10001; ++i)
            dp[i] = max(dp[i-1], dp[i-2] + dp[i]);
        return dp.back();
    }
};