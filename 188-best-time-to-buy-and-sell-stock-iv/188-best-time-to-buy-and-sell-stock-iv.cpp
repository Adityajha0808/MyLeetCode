class Solution {
public:
    int maxProfit(int k, vector<int>& a) {
        int n = a.size();
        if(k >= n/2) {
            int res = 0;
            for(int i=1; i<n; ++i)
                res += max(0, a[i] - a[i - 1]);
            return res;
        }
        vector<int> dp1(k + 1, INT_MIN), dp2(k + 1, 0);
        for(auto& i : a) {
            for(int j=1; j<=k; ++j) {
                dp1[j] = max(dp1[j], dp2[j - 1] - i);
                dp2[j] = max(dp2[j], dp1[j] + i); 
            }
        }
        return dp2[k];
    }
};