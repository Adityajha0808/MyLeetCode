class Solution {
public:
    int longestStrChain(vector<string>& a) {
        int n = a.size(), res = 1;
        unordered_map<string, int> mp;
        sort(a.begin(), a.end(), [](string& l, string& r) {
            return l.size() < r.size();
        });
        for(auto i: a) {
            mp[i] = 1;
            for(int j=0; j<i.size(); ++j) {
                string s = i.substr(0, j) + i.substr(j + 1);
                if(mp.find(s) != mp.end()) {
                    mp[i] = mp[s] + 1;
                    res = max(res, mp[i]);
                }
            }
        }
        return res;
    }
};