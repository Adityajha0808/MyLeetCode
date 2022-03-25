class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& a) {
        int n = a.size()/2, res = 0, cnt = 0;
        sort(a.begin(), a.end(), [](vector<int>& x, vector<int>& y) {
            return x[0] - x[1] < y[0] - y[1];
        });
        for(auto i: a) {
            if(cnt < n) {
                res += i[0];
                cnt++;
            } else
                res += i[1];
        }
        return res;
    }
};