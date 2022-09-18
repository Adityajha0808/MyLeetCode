using ll = long long;
class Solution {
public:
    ll maxll(ll a, ll b) {
        if(a > b) return a;
        return b;
    }
    ll minimumMoney(vector<vector<int>>& a) {
        ll res = 0, minm = -1;
        for(auto& i: a)
            res = maxll(res, min(i[0], i[1]));
        for(auto& i: a)
            res += maxll(i[0] - i[1], 0);
        return res;
    }
};