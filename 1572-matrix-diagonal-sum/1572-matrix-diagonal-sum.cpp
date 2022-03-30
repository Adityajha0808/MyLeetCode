class Solution {
public:
    int diagonalSum(vector<vector<int>>& a) {
        int n = a.size(), res = 0;
        for(int i=0; i<n; ++i) {
            for(int j=0; j<n; ++j) {
                if(i == j or n-1-i == j) res += a[i][j];
            }
        }
        return res;
    }
};