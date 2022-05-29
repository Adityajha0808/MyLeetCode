class Solution {
public:
    int maxProduct(vector<string>& a) {
        int n = a.size(), res = 0;
        vector<int> v(n,0);
        for(int i=0; i<n; ++i) {
            for(auto j: a[i]) v[i] |= 1 << (j - 'a');
            for(int j=0; j<i; ++j)
                if((v[i] & v[j]) == false)
                    res = max(res, int(a[i].size() * a[j].size()));
        }
        return res;
    }
};