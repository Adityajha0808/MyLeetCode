class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> mp1, mp2;
        for(auto& i: s) mp1[i]++;
        for(auto& i: t) mp2[i]++;
        if(mp1 == mp2) return 0;
        int res = 0;
        for(auto& i: mp1) {
            if(mp2.find(i.first) == mp2.end()) {
                res += i.second;
                mp2.insert({i.first, i.second});
            } else {
                auto it = mp2.find(i.first);  
                res += abs(i.second - it->second);
                i.second = max(i.second, it->second);
                it->second = max(i.second, it->second);
            }
        }
        for(auto& i: mp2) {
            if(mp1.find(i.first) == mp1.end())
                res += i.second;
            else {
                auto it = mp1.find(i.first);
                res += abs(i.second - it->second);
            }
        }
        return res;
    }
};