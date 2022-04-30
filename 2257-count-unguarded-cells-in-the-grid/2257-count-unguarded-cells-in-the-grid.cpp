class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& g, vector<vector<int>>& w) {
        vector<vector<int>> a(m , vector<int> (n, 0));
        for(auto i: w) a[i[0]][i[1]] = -1;
        for(auto i: g) a[i[0]][i[1]] = 1;
        for(auto i: g) {
            for(int j=i[0]-1; j>=0; --j) {
                if(a[j][i[1]] == -1 or a[j][i[1]] == 1) break;
                a[j][i[1]] = 2;
            }
            for(int j=i[0]+1; j<m; ++j) {
                if(a[j][i[1]] == -1 or a[j][i[1]] == 1) break;
                a[j][i[1]] = 2;
            }
            for(int j=i[1]+1; j<n; ++j) {
                if(a[i[0]][j] == -1 or a[i[0]][j] == 1) break;
                a[i[0]][j] = 2;
            }
            for(int j=i[1]-1; j>=0; --j) {
                if(a[i[0]][j] == -1 or a[i[0]][j] == 1) break;
                a[i[0]][j] = 2;
            }
        }
        int res = 0;
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                if(a[i][j] == 0) res++;
            }
        }
        return res;
    }
};