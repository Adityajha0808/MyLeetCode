class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& a, int k) {
        set<vector<int>> s;
        for(auto& i: a)
            s.insert(i);
        a.clear();
        for(auto& i: s)
            a.push_back(i);
        unordered_map<int,int> mp;
        for(auto& i: a)
            mp[i[0]]++;
        vector<int> res(k,0);
        for(auto& i: mp)
            res[i.second - 1]++;
        return res;
    }
};