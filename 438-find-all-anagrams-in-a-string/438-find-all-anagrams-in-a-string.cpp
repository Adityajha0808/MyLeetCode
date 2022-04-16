class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), k = p.size();
        vector<int> a1(26), a2(26), v;
        for(auto i: p) a2[i - 'a']++;
        for(int i=0; i<n; ++i) {
            a1[s[i] - 'a']++;
            if(i >= k) a1[s[i - k] - 'a']--;
            if(a1 == a2) v.push_back(i - k + 1);
        }
        return v;
    }
};