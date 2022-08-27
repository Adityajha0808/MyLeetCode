class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& a) {
        int m = a.size(), n = a[0].size();
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mp;
        for(int i=0; i<m; ++i)
            for(int j=0; j<n; ++j)
                mp[i-j].push(a[i][j]);
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                a[i][j] = mp[i-j].top();
                mp[i-j].pop();
            }
        }
        return a;
    }
};