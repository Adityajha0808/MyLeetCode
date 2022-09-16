class Solution {
public:
    int maximumScore(vector<int>& a, vector<int>& mul) {
        int n = a.size(), m = mul.size();
        vector<int> dp(m+1, 0), vec;
        for(int i=m-1; ~i; --i) {
            vec = dp;
            for(int j=i; ~j; --j) {
                dp[j] = max(mul[i] * a[j] + vec[j+1], mul[i] * a[n-1-i+j] + vec[j]);
            }
        }
        return dp.front();
    }
};