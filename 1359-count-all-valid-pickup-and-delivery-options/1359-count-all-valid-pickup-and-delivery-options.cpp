using ll = long long;
class Solution {
public:
    int countOrders(int n) {
        ll res = 1, mod = 1e9 + 7;
        for(int i=1; i<=n; ++i) {
            res = (res * (2*i - 1) * i) % mod;
        }
        return res;
    }
};