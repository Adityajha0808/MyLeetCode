class Solution {
public:
    void rotate(vector<vector<int>>& a) {
        int m = a.size(), n = a[0].size(), k = 0;
        for(int i=0; i<m; ++i) {
            for(int j=k; j<n; ++j) {
                if(i!=j)
                    swap(a[i][j], a[j][i]);
            }
            k++;
        }
        for(int i=0; i<m; ++i) {
            reverse(a[i].begin(), a[i].end());
        }
    }
};