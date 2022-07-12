class Solution {
public:
    bool func(vector<int>& a, vector<int>& v, int start, int sum, int k, int x) {
        if(k == 1) return true;
        if(sum > x) return false;
        if(sum == x) return func(a, v, 0, 0, k-1, x);
        for(int i=start; i<a.size(); i++) {
            if(!v[i]) {
                v[i] = 1;
                if(func(a, v, i+1, sum + a[i], k, x)) return true;
                v[i] = 0;
            }
        }
        return false;
    }
    bool makesquare(vector<int>& a) {
        int n = a.size(), sum = 0;
        for(auto i: a) sum += i;
        if(sum % 4) return false;
        vector<int> v(n, 0);
        return func(a, v, 0, 0, 4, sum/4);
    }
};