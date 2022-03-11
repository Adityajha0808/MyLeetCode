class Solution {
public:
    int maxProfit(vector<int>& a, int fee) {
        int res = 0, hold = -1 * a[0];
        if(a.size() == 1) return 0;
        for(auto& i: a) {
            res = max(res, hold + i - fee);
            hold = max(hold, res - i);
        }
        return res;
    }
};