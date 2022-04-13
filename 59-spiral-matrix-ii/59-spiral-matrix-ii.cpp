class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> a(n, vector<int> (n));
        int r = n, c = n, row = 0, col = 0, counter = 1;
        while(row < r and col < c) {
            for(int i=col; i<c; ++i) {
                a[row][i] = counter;
                counter++;
            }
            row++;
            for(int i=row; i<r; ++i) {
                a[i][c-1] = counter;
                counter++;
            }
            c--;
            if(row < r) {
                for(int i=c-1; i>=col; --i) {
                    a[r-1][i] = counter;
                    counter++;
                }
                r--;
            }
            if(col < c) {
                for(int i=r-1; i>=row; --i) {
                    a[i][col] = counter;
                    counter++;
                }
                col++;
            }
        }
        return a;
    }
};