class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& r) {
        unordered_map<int,int> mp;
        for(auto i: r) mp[i[0]]++, mp[i[1]]++;
        vector<vector<int>> a;
        for(auto i: mp) a.push_back({i.second,i.first});
        sort(a.begin(), a.end());
        vector<int> zo(n,0);
        int sz = a.size();
        if(mp.size() < n)
            for(int i=sz-1; i>=0; --i)
                zo[a[i][1]] = n--;
        else
            for(int i=0; i<sz; ++i)
                zo[a[i][1]] = i+1;
        long long res = 0;
        for(auto i: r) res += zo[i[0]] + zo[i[1]];
        return res;
    }
};