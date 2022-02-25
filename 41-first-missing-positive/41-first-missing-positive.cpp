class Solution {
public:
    int firstMissingPositive(vector<int>& a) {
        int n = a.size(), j = 0;
        for(int i=0; i<n; ++i) {
            while(a[i] > 0 and a[i] <= n and a[a[i] - 1] != a[i]) {
                swap(a[a[i]-1], a[i]);
            }
        }
        for(int i=0; i<n; ++i) {
            if(a[i] != j+1) return j+1;
            j++;
        }
        return n+1;
    }
};