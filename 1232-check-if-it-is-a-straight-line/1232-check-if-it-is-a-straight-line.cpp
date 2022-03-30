class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& a) {
        int n = a.size();
        for(int i=2; i<n; ++i) {
            if((a[i][1] - a[0][1]) * (a[1][0] - a[0][0]) != (a[1][1] - a[0][1]) * (a[i][0] - a[0][0]))
                return false;
        }
        return true;
    }
};