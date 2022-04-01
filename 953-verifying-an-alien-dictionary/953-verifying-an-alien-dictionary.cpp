class Solution {
public:
    bool isAlienSorted(vector<string>& w, string o) {
        unordered_map<char,char> mp;
        for(int i=0; i<o.size(); ++i) mp[o[i]] = 'a' + i;
        for(auto& i: w) {
            for(auto& j: i)
                j = mp[j];
        }
        return is_sorted(w.begin(), w.end());
    }
};