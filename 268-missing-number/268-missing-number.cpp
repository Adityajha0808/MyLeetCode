class Solution {
public:
    int missingNumber(vector<int>& a) {
        int n = a.size(), sum = 0, sum2 = (n*(n+1))/2;
        for(auto i: a) sum += i;
        return sum2 - sum;
    }
};