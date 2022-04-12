class Solution {
public:
    void gameOfLife(vector<vector<int>>& a) {
        int m = a.size(), n = a[0].size();
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                int cnt = 0;
                if(i>0 and j>0) cnt += a[i-1][j-1] > 1 ? a[i-1][j-1] - 2 : a[i-1][j-1];
                if(i>0) cnt += a[i-1][j] > 1 ? a[i-1][j] - 2 : a[i-1][j];
                if(i>0 and j<n-1) cnt += a[i-1][j+1] > 1 ? a[i-1][j+1] - 2 : a[i-1][j+1];
                if(j>0) cnt += a[i][j-1] > 1 ? a[i][j-1] - 2 : a[i][j-1];
                if(j<n-1) cnt += a[i][j+1] > 1 ? a[i][j+1] - 2 : a[i][j+1];
                if(i<m-1 and j>0) cnt += a[i+1][j-1] > 1 ? a[i+1][j-1] - 2 : a[i+1][j-1];
                if(i<m-1) cnt += a[i+1][j] > 1 ? a[i+1][j] - 2 : a[i+1][j];
                if(i<m-1 and j<n-1) cnt += a[i+1][j+1] > 1 ? a[i+1][j+1] - 2 : a[i+1][j+1];
                if(cnt == 3 or (cnt == 2 and a[i][j])) a[i][j] += 2;
            }
        }
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                a[i][j] /= 2;
            }
        }
    }
};