class NumMatrix {
public:
    vector<vector<int>> a;
    NumMatrix(vector<vector<int>>& matrix) {
        a = matrix;
        int n = a.size(), m = a[0].size();
        for(int i=0; i<n; ++i) {
            for(int j=1; j<m; ++j) {
                a[i][j] += a[i][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for(int i=row1; i<=row2; ++i) {
            if(col1-1 < 0) {
                sum += a[i][col2];
            } else
            sum += a[i][col2] - a[i][col1-1];
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */