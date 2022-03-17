class Solution {
public:
    int minIncrementForUnique(vector<int>& a) {
        int n = a.size(), res = 0;
        sort(a.begin(), a.end());
        for(int i=1; i<n; ++i) {
            if(a[i] <= a[i-1]) {
                res += a[i-1] + 1 - a[i];
                a[i] = a[i-1] + 1;
            }
        }
        return res;
    }
};