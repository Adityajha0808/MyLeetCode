class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n = a.size();
        vector<int> dp(n, 1);
        int l = 1;
        for(int i=1; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(a[i] > a[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    l = max(l, dp[i]);
                }
            }
        }
        return l;
    }
};