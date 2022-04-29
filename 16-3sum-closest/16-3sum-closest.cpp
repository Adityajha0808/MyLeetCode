class Solution {
public:
    int threeSumClosest(vector<int>& a, int target) {
        sort(a.begin(), a.end());
        int n = a.size();
        int res = a[0] + a[1] + a[2];
        int curr = 0, j, k;
        for(int i=0; i<n; i++) {
            j = i+1, k = n-1;
            while(j<k) {
                curr = a[i] + a[j] + a[k];
                if(abs(curr - target) < abs(res - target)) {
                    res = curr;
                }
                (curr < target) ? j++ : k--;
            }
        }
        return res;
    }
};