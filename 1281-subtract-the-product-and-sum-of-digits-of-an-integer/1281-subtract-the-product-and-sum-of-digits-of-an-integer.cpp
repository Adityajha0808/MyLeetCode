class Solution {
public:
    int subtractProductAndSum(int n) {
        string s = to_string(n);
        long long prod = 1, sum = 0;
        for(auto i: s) {
            prod *= (i - '0');
            sum += (i - '0');
        }
        return prod - sum;
    }
};