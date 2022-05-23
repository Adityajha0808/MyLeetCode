class Solution {
public:
    int findMaxForm(vector<string>& s, int zero, int ones) {
        int n = s.size();
        vector<vector<int>> dp(zero+1, vector<int>(ones+1));
        for(auto i: s) {
            int z = count(i.begin(), i.end(), '0'), o = i.size() - z;
            for(int j=zero; j>=z; --j) {
                for(int k=ones; k>=o; --k) {
                    dp[j][k] = max(dp[j][k], dp[j-z][k-o] + 1);
                }
            }
        }
        return dp[zero][ones];
    }
};