class Solution {
public:
    int rearrangeCharacters(string s, string t) {
        vector<int> a(26,0), v(26,0);
        for(auto i: s) a[i-'a']++;
        for(auto i: t) v[i-'a']++;
        int res = INT_MAX;
        for(int i=0; i<26; ++i) {
            if(v[i] == 0) continue;
            res = min(res, a[i]/v[i]);
        }
        return res;
    }
};