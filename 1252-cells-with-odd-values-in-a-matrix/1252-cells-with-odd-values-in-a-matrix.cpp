class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& idx) {
        vector<vector<int>> a(m, vector<int>(n, 0));
        for(auto i: idx) {
            for(int j=0; j<n; ++j)
                a[i[0]][j]++;
            for(int j=0; j<m; ++j)
                a[j][i[1]]++;
        }
        int cnt = 0;
        for(int i=0; i<m; ++i)
            for(int j=0; j<n; ++j)
                if(a[i][j]%2)
                    cnt++;
        return cnt;
    }
};