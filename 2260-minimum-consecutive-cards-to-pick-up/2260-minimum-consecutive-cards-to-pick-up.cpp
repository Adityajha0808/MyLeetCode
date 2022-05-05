class Solution {
public:
    int minimumCardPickup(vector<int>& a) {
        int n = a.size(), res = INT_MAX;
        vector<int> v(1000001, -1);
        for(int i=0; i<n; ++i) {
            if(v[a[i]] != -1)
                res = min(res, i - v[a[i]] + 1);
            v[a[i]] = i;
        }
        return (res == INT_MAX ? -1 : res);
    }
};