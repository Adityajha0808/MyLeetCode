class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        double x = ((double)log10(n) / (double)log10(3));
        return (x == floor(x));
    }
};