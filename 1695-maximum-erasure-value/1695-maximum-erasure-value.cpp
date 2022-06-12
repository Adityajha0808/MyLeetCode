class Solution {
public:
    int maximumUniqueSubarray(vector<int>& a) {
        int n = a.size(), res = 0, idx = 0, curr = 0;
        unordered_set<int> s;
        for(int i=0; i<n; ++i) {
            while(s.find(a[i]) != s.end()) {
                s.erase(a[idx]);
                curr -= a[idx];
                idx++;
            }
            s.insert(a[i]);
            curr += a[i];
            res = max(res, curr);
        }
        return res;
    }
};