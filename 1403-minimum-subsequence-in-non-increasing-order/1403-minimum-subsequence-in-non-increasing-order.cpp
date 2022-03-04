class Solution {
public:
    vector<int> minSubsequence(vector<int>& a) {
        sort(a.begin(), a.end());
        int n = a.size(), sum = accumulate(a.begin(), a.end(), 0), curr = 0, i;
        vector<int> res;
        for(i=n-1; i>=0; --i) {
            res.push_back(a[i]);
            if(a[i] + curr > sum - a[i] - curr) break;
            curr += a[i];
        }
        return res;
    }
};