class Solution {
public:
    int maximumUnits(vector<vector<int>>& a, int k) {
        sort(a.begin(), a.end(), [](vector<int>& x, vector<int>& y) {
            return (x[1] == y[1] ? x[0] > y[0] : x[1] > y[1]);
        });
        int sum = 0;
        for(auto i: a) {
            if(k < i[0]) {
                sum += k * i[1];
                break;
            }
            sum += i[0] * i[1];
            k -= i[0];
        }
        return sum;
    }
};