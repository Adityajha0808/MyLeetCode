class Solution {
public:
    vector<string> summaryRanges(vector<int>& a) {
        int n = a.size();
        if(n == 0) return {};
        vector<string> res;
        int start = 0, curr = 0;
        for(int i=1; i<n; ++i) {
            if(a[i] - 1 == a[curr]) {
                curr = i;
                continue;
            } else {
                if(start == curr)
                    res.push_back(to_string(a[start]));
                else
                    res.push_back(to_string(a[start]) + "->" + to_string(a[curr]));
                start = i, curr = i;
            }
        }
        if(start == curr)
            res.push_back(to_string(a[start]));
        else
            res.push_back(to_string(a[start]) + "->" + to_string(a[curr]));
        return res;
    }
};