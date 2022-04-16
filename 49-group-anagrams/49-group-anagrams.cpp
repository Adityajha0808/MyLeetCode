class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& a) {
        int n = a.size();
        unordered_map<string, vector<string>> mp;
        string s;
        for(auto i: a) {
            s = i;
            sort(i.begin(), i.end());
            mp[i].push_back(s);
        }
        vector<vector<string>> vect;
        for(auto i: mp) {
            vect.push_back(i.second);
        }
        return vect;
    }
};