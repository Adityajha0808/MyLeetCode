class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& a) {
        int n = a.size()/2, res = 0;
        sort(a.begin(), a.end(), [](vector<int>& x, vector<int>& y) {
            return x[0] - x[1] < y[0] - y[1];
        });
        for(int i=0; i<n; ++i) res += a[i][0];
        for(int i=n; i<2*n; ++i) res += a[i][1];
        return res;
    }
};