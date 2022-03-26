class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& a) {
        int n = a.size(), res = INT_MAX, idx = -1;
        for(int i=0; i<n; ++i) {
            if((a[i][0] == x or a[i][1] == y) and (abs(x - a[i][0]) + abs(y - a[i][1]) < res)) {
                res = abs(x - a[i][0]) + abs(y - a[i][1]);
                idx = i;
            }
        }
        return idx;
    }
};