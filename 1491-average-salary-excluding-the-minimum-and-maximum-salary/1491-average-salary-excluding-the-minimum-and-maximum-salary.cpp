class Solution {
public:
    double average(vector<int>& a) {
        sort(a.begin(), a.end());
        long long n = a.size(), sum = 0;
        for(int i=1; i<n-1; ++i) sum += a[i];
        return (double)sum/(n-2);
    }
};