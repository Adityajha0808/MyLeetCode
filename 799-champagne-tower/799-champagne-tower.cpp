class Solution {
public:
    double champagneTower(int poured, int row, int glass) {
        vector<vector<double>> dp(102, vector<double> (102,0));
        dp[0][0] = (double)poured;
        for(int i=0; i<=row; ++i) {
            for(int j=0; j<=i; ++j) {
                double x = dp[i][j] - 1.0;
                if(x > 0) {
                    dp[i+1][j] += x/2.0;
                    dp[i+1][j+1] += x/2.0;
                }
            }
        }
        if(dp[row][glass] < 1.0) return dp[row][glass];
        return 1.0;
    }
};