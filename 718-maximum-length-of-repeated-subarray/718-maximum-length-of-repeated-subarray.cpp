class Solution {
public:
    int findLength(vector<int>& a1, vector<int>& a2) {
        int n1 = a1.size(), n2 = a2.size(), res = 0;
        vector<vector<int>> dp(n1+1, vector<int> (n2+1, 0));
        for(int i=n1-1; ~i; --i) {
            for(int j=n2-1; ~j; --j) {
                if(a1[i] == a2[j]) {
                    dp[i][j] = dp[i+1][j+1] + 1;
                    res = max(res, dp[i][j]);
                }
            }
        }
        return res;
    }
};