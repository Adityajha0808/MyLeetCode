class Solution {
public:
    bool canPartition(vector<int>& a) {
        int sum = accumulate(a.begin(), a.end(), 0);
        if(sum%2) return false;
        sum /= 2;
        vector<bool> dp(sum+1, false);
        dp[0] = true;
        for(int i=0; i<a.size(); ++i) {
            for(int j=sum; j>0; --j) {
                if(j >= a[i]) {
                    dp[j] = (dp[j] or dp[j-a[i]]);
                }
            }
        }
        return dp[sum];
    }
};