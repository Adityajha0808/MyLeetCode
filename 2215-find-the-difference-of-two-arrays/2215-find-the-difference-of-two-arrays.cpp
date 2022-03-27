class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& a1, vector<int>& a2) {
        unordered_map<int,int> mp1, mp2;
        for(auto i: a1) mp1[i]++;
        for(auto i: a2) mp2[i]++;
        vector<vector<int>> res;
        vector<int> v;
        for(auto i: mp1) {
            if(mp2.find(i.first) == mp2.end())
                v.push_back(i.first);
        }
        res.push_back(v);
        v.clear();
        for(auto i: mp2) {
            if(mp1.find(i.first) == mp1.end())
                v.push_back(i.first);
        }
        res.push_back(v);
        return res;
    }
};