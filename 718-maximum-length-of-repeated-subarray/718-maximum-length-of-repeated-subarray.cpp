class Solution {
public:
    int findLength(vector<int>& a1, vector<int>& a2) {
        int n1 = a1.size(), n2 = a2.size(), res = 0;
        vector<vector<bool>> dp(n1, vector<bool> (n2, false));
        for(int i=0; i<n1; ++i) {
            for(int j=0; j<n2; ++j) {
                if(a1[i] == a2[j])
                    dp[i][j] = true;
            }
        }
        for(int k=0; k<n1; ++k) {
            int i=k, j = n2-1, cnt = 0;
            while(i>=0 and j>=0) {
                if(dp[i][j])
                    cnt++;
                else {
                    res = max(res, cnt);
                    cnt = 0;
                }
                i--;
                j--;
            }
            res = max(res, cnt);
        }
        for(int k=n2-2; ~k; --k) {
            int i=k, j = n1-1, cnt = 0;
            while(i>=0 and j>=0) {
                if(dp[j][i])
                    cnt++;
                else {
                    res = max(res, cnt);
                    cnt = 0;
                }
                i--;
                j--;
            }
            res = max(res, cnt);
        }
        return res;
    }
};