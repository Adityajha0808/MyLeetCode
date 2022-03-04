class Solution {
public:
    vector<int> minSubsequence(vector<int>& a) {
        int n = a.size();
        sort(a.begin(), a.end());
        int sum = accumulate(a.begin(), a.end(), 0), curr = 0, i;
        for(i=n-1; i>=0; --i) {
            if(a[i] + curr > sum - a[i] - curr) break;
            curr += a[i];
        }
        vector<int> res;
        for(int j=n-1; j>=i; --j) res.push_back(a[j]);
        return res;
    }
};