class Solution {
public:
    int powerOfTwo(int n) {
        return ((n & (n-1)) == 0 ? true : false);
    }
    long func(int n) {
        int res = 0;
        while(n > 0) {
            res += pow(10, n%10);
            n /= 10;
        }
        return res;
    }
    bool reorderedPowerOf2(int n) {
        if(powerOfTwo(n)) return true;
        int cnt = func(n);
        for(int i=0; i<32; ++i)
            if(func(1 << i) == cnt) return true;
        return false;
    }
};