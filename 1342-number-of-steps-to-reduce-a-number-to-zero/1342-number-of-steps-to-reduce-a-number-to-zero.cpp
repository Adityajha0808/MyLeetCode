class Solution {
public:
    int numberOfSteps(int n) {
        return n ? __builtin_popcount(n) + log2(n) : 0;
    }
};