using ll = long long;
class Solution {
public:
    int threeSumMulti(vector<int>& arr, int x) {
        ll res = 0;
        unordered_map<int,ll> mp;
        for(auto i: arr) mp[i]++;
        for(auto i: mp) {
            for(auto j: mp) {
                int a = i.first, b = j.first, c = x - a - b;
                if(mp.count(c) == 0) continue;
                if(a == b and b == c) {
                    res += (mp[a] * (mp[a] - 1) * (mp[a] - 2)/6);
                } else if(a == b and b != c) {
                    res += (mp[a] * (mp[a] - 1) / 2 * mp[c]);
                }
                else if(a < b and b < c) {
                    res += (mp[a] * mp[b] * mp[c]);
                }
            }
        }
        return res%1000000007;
    }
};