class Solution {
public:
    int minDistance(string s1, string s2) {
        int l1 = s1.size(), l2 = s2.size();
        vector<vector<int>> dp(l1+1, vector<int>(l2+1, 0));
        for(int i=0; i<=l1; ++i) {
            for(int j=0; j<=l2; ++j) {
                if(i == 0 or j == 0) continue;
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return l1 + l2 - 2 * dp[l1][l2];
    }
};