class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        double x = (double)log10(n) / (double)log10(2);
        return (x == floor(x));
    }
};