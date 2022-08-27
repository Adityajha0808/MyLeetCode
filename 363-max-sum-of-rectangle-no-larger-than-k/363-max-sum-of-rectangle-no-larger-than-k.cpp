class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& a, int k) {
        int m = a.size(), n = a[0].size(), res = INT_MIN;
        for(int i=0; i<n; ++i) {
            vector<int> v(m);
            for(int j=i; j<n; ++j) {
                for(int k=0; k<m; ++k)
                    v[k] += a[k][j];
                set<int> s = {0};
                int sum = 0;
                for(auto x: v) {
                    sum += x;
                    auto it = s.lower_bound(sum - k);
                    if(it != s.end())
                        res = max(res, sum - *it);
                    s.insert(sum);
                }
            }
        }
        return res;
    }
};