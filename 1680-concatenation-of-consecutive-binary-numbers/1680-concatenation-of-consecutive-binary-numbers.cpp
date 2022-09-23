class Solution {
public:
    int mod = 1e9 + 7;
    int concatenatedBinary(int n) {
        long long res = 0;
        for(int i=1; i<=n; ++i) {
            res = ((res << (int)(log2(i) + 1)) % mod + i) % mod;
        }
        return res;
    }
};