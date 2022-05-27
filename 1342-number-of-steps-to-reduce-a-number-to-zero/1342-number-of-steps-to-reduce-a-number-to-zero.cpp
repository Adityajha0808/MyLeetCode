class Solution {
public:
    int numberOfSteps(int n) {
        if(n) return __builtin_popcount(n) + log2(n);
        return 0;
    }
};