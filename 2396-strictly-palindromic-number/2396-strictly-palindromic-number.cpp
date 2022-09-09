class Solution {
public:
    bool funcCheck(int n, int x) {
        vector<int> a, v;
        while(n > 0) {
            a.push_back(n%x);
            n /= x;
        }
        v = a;
        reverse(v.begin(), v.end());
        return (a == v);
    }
    bool isStrictlyPalindromic(int n) {
        for(int i=2; i<n-1; ++i) {
            if(!funcCheck(n, i)) return false;
        }
        return true;
    }
};