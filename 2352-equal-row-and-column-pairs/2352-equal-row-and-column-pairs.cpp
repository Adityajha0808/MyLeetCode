class Solution {
public:
    int equalPairs(vector<vector<int>>& a) {
        int n = a.size(), res = 0;
        map<vector<int>, int> mp;
        for(int i=0; i<n; ++i) {
            mp[a[i]]++;
        }
        vector<int> v;
        for(int j=0; j<n; ++j) {
            for(int i=0; i<n; ++i) {
                v.push_back(a[i][j]);
            }
            if(mp.find(v) != mp.end()) {
                res += mp.find(v)->second;
            }
            v.clear();
        }
        return res;
    }
};