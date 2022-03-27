using ll = long long;
class Solution {
public:
    vector<ll> res;
    void zoran(ll n, ll k) {
        ll tmp = (k%2) ? (k / 2) : (k/2 - 1), pal = (ll)pow(10, tmp) + n - 1;
        string s = to_string(pal);
        if(k%2) pal /= 10;
        while(pal) {
            s += to_string(pal%10);
            pal /= 10;
        }
        res.push_back(s.size() <= k+1 ? stoll(s) : -1);
    }
    vector<ll> kthPalindrome(vector<int>& q, int l) {
        for(auto i: q) zoran(i, l);
        return res;
    }
};