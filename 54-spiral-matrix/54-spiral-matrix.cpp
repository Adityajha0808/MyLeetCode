class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) {
        int m = a.size(), n = a[0].size(), i, k = 0, l = 0;
        vector<int> v;
        while(k < m && l < n) {
            for(i=l; i<n; i++) v.push_back(a[k][i]);
            k++;
            for(i=k; i<m; i++) v.push_back(a[i][n-1]);
            n--;
            if(k < m) {
                for(i=n-1; i>=l; i--) v.push_back(a[m-1][i]);
                m--;
            }
            if(l < n) {
                for(i=m-1; i>=k; i--) v.push_back(a[i][l]);
                l++;
            }
        }
        return v;
    }
};