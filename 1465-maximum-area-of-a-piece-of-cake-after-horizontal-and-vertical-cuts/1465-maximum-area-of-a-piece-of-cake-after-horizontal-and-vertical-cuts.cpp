class Solution {
public:
    int maxArea(int len, int brd, vector<int>& h, vector<int>& v) {
        sort(h.begin(), h.end());
        sort(v.begin(), v.end());
        int n1 = h.size(), n2 = v.size(), maxh = max(h[0], len - h.back()), maxv = max(v[0], brd - v.back()), mod = 1e9 + 7;
        for(int i=1; i<n1; ++i)
            maxh = max(maxh, h[i] - h[i-1]);
        for(int i=1; i<n2; ++i)
            maxv = max(maxv, v[i] - v[i-1]);
        return ((long long)maxh * maxv) % mod;
    }
};