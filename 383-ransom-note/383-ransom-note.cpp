class Solution {
public:
    bool canConstruct(string r, string m) {
        unordered_map<char,int> mp;
        for(auto i: m) mp[i]++;
        for(auto i: r) {
            if(!mp[i]) return false;
            mp[i]--;
        }
        return true;
    }
};