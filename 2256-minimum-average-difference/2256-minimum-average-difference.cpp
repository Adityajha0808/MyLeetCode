using ll = long long;
class Solution {
public:
    int minimumAverageDifference(vector<int>& a) {
        int n = a.size(), res = INT_MAX, idx = -1;
        vector<ll> p(n,0);
        p[0] = a[0];
        for(int i=1; i<n; ++i) p[i] = p[i - 1] + a[i];
        for(int i=0; i<n; ++i) {
            int left = p[i]/(i+1), right = (i == n-1 ? 0 : (p[n-1] - p[i])/(n-i-1));
            if(abs(right - left) < res) {
                res = abs(right - left);
                idx = i;
            }
        }
        return idx;
    }
};