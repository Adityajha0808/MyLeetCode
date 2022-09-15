class Solution {
public:
    vector<int> findOriginalArray(vector<int>& a) {    
        int n = a.size();
        if(n%2) return {};
        unordered_map<int,int> mp;
        for(int i: a) mp[i]++;
        vector<int> v;
        for(auto i: mp) v.push_back(i.first);
        sort(v.begin(), v.end());
        vector<int> res;
        for(int i: v) {
            if(mp[i] > mp[2*i]) return {};
            for(int j=0; j<mp[i]; j++) {
                res.push_back(i);
                mp[2*i]--;
            }
        }
        return res;
    }
};