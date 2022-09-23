class Solution {
public:
    int mod = 1e9 + 7;
    int bits(int n) {
        return log2(n) + 1;
    }
    int concatenatedBinary(int n) {
        long long res = 0;
        for(int i=1; i<=n; ++i) {
            res = ((res << bits(i))%mod + i)%mod;
        }
        return res;
    }
};