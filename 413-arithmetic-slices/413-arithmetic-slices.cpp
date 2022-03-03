class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& a) {
        int n = a.size(), curr = 0, sum = 0;
        for(int i=2; i<n; i++) {
            if(a[i] - a[i-1] == a[i-1] - a[i-2]) {
                curr++;
                sum += curr;
            } else curr = 0;
        }
        return sum;
    }
};