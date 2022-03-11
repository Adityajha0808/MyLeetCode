class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n = a.size();
        if(n==1) return 0;
        int res = max(0, a[1] - a[0]);
        for(int i=1; i<n-1; ++i) {
            res += max(0, a[i+1] - a[i]);
        }
        return res;
    }
};