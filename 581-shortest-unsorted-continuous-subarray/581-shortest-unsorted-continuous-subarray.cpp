class Solution {
public:
    int findUnsortedSubarray(vector<int>& a) {
        int n = a.size(), minm = INT_MAX, maxm = INT_MIN, l, r;
        bool flag = false;
        for(int i=1; i<n; ++i) {
            if(a[i] < a[i-1]) flag = true;
            if(flag) minm = min(minm, a[i]);
        }
        flag = false;
        for(int i=n-2; i>=0; --i) {
            if(a[i] > a[i+1]) flag = true;
            if(flag) maxm = max(maxm, a[i]);
        }
        for(l=0; l<n; ++l)
            if(minm < a[l]) break;
        for(r=n-1; r>=0; --r)
            if(maxm > a[r]) break;
        if(r - l < 0) return 0;
        return r - l + 1;
    }
};