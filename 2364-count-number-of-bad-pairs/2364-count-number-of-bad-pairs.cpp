using ll = long long;
class Solution {
public:
    ll countBadPairs(vector<int>& a) {
        int n = a.size();
        ll res = ((ll)n * (n-1))/2, good = 0;
        unordered_map<int,int> mp;
        for(int i=0; i<n; ++i) {
            if(mp.find(a[i] - i) != mp.end())
                good += mp.find(a[i] - i)->second;
            mp[a[i] - i]++;
        }
        return res - good;
    }
};