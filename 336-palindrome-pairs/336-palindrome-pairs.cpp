class Solution {
public:
    bool isPal(string s) {
        string x = s;
        reverse(x.begin(), x.end());
        return (x == s);
    }
    vector<vector<int>> palindromePairs(vector<string>& a) {
        int n = a.size();
        vector<vector<int>> res;
        unordered_map<string, int> mp;
        for(int i=0; i<n; ++i) {
             string s = a[i];
             reverse(s.begin(), s.end());
             mp[s] = i;
        }
        if(mp.find("") != mp.end()) {
            for(int i=0; i<n; ++i) {
                if(i == mp[""]) continue;
                if(isPal(a[i])) res.push_back({mp[""], i});
            }
        }
        for(int i=0; i<n; ++i) {
            for(int j=0; j < a[i].size(); ++j) {
                string l = a[i].substr(0, j), r = a[i].substr(j, a[i].size() - j);
                if(mp.find(l) != mp.end() and isPal(r) and mp[l] != i)
                    res.push_back({i, mp[l]});
                if(mp.find(r) != mp.end() and isPal(l) and mp[r] != i)
                    res.push_back({mp[r], i});
            }
        }
        return res;
    }
};