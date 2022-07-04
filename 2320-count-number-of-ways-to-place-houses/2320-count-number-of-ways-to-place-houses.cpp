using ll = long long;
class Solution {
public:
    int mod = 1e9 + 7;
    ll fib(int n) {
        ll a = 0, b = 1, c, i;
        for(i=2; i<=n; ++i) {
            c = (a + b)%mod;
            a = b;
            b = c;
        }
        return b;
    }
    int countHousePlacements(int n) {
        ll res = fib(n+2);
        return (res*res)%mod;
    }
};