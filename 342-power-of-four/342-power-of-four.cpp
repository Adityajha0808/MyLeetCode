class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) return false;
        double x = (double)log10(n) / (double)log10(4);
        return (x == floor(x));
    }
};