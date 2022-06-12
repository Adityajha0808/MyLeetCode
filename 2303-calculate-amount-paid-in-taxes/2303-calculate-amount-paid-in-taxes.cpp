class Solution {
public:
    double calculateTax(vector<vector<int>>& a, int k) {
        int n = a.size();
        double res = 0.0;
        // if(k == 0) return res;
        for(int i=0; i<n; ++i) {
            double per = (double)a[i][1]/100;
            if(i == 0) {
                if(a[i][0] > k) {
                    res += k * per;
                    break;
                }
                res += per * a[i][0];
            } else {
                double diff = 0.0;
                if(a[i][0] > k) {
                    diff = k - a[i-1][0];
                    res += per * diff;
                    break;
                } else
                    diff = a[i][0] - a[i-1][0];
                res += per * diff;
            }
        }
        return res;
    }
};