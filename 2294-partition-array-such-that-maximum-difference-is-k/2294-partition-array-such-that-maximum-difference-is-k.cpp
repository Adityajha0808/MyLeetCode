class Solution {
public:
    int partitionArray(vector<int>& a, int k) {
        sort(a.begin(), a.end());
        int n = a.size(), res = 0, minm = a[0];
        for(int i=1; i<n; ++i) {
            if(a[i] - minm > k) {
                res++;
                minm = a[i];
            }
        }
        return res+1;
    }
};