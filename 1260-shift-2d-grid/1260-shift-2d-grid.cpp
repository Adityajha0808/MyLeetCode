class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& a, int k) {
        int m = a.size(), n = a[0].size();
        while(k--) {
            vector<vector<int>> v(m, vector<int> (n, 0));
            for(int i=0; i<m; ++i) {
                for(int j=0; j<n; ++j) {
                    if(j == 0) {
                        if(i == 0) {
                            v[i][j] = a[m-1][n-1];
                        } else
                        v[i][j] = a[i-1][n-1];
                    } else
                    v[i][j] = a[i][j-1];
                }
            }
            a = v;
        }
        return a;
    }
};