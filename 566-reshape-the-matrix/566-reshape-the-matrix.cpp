class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(), n = mat[0].size();
        vector<int> a;
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                a.push_back(mat[i][j]);
            }
        }
        vector<vector<int>> res;
        int k = 0;
        if(r*c > m*n) {
            r = m;
            c = n;
        }
        if(r*c < m*n) {
            r = m;
            c = n;
        }
        for(int i=0; i<r; ++i) {
            vector<int> temp;
            for(int j=0; j<c; ++j) {
                temp.push_back(a[k]);
                k++;
            }
            res.push_back(temp);
            temp.clear();
        }
        return res;
    }
};