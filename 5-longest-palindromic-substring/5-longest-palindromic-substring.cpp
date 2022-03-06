class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n==1) return s;
        string res;
        vector<vector<bool>> dp(n, vector<bool> (n));
        for(int i=n-1; i>=0; --i) {
            for(int j=i; j<n; ++j) {
                dp[i][j] = (s[i] == s[j] and (j-i < 3 or dp[i+1][j-1]));
                if(dp[i][j] and j-i+1 > res.size()) {
                    res = s.substr(i, j-i+1);
                }
            }
        }
        return res;
    }
};