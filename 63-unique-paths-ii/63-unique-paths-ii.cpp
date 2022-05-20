class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        if(a[0][0] or a[n-1][m-1]) return 0;
        a[0][0] = 1;
        for(int i=1; i<n; ++i) {
            if(a[i][0] == 0 and a[i-1][0])
                a[i][0] = 1;
            else
                a[i][0] = 0;
        }
        for(int i=1; i<m; ++i) {
            if(a[0][i] == 0 and a[0][i-1])
                a[0][i] = 1;
            else
                a[0][i] = 0;
        }
        for(int i=1; i<n; ++i)
            for(int j=1; j<m; ++j)
                a[i][j] = (a[i][j] ? 0 : a[i-1][j] + a[i][j-1]);
        return a[n-1][m-1];
    }
};