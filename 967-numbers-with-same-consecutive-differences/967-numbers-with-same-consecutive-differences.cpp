class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> res = {1,2,3,4,5,6,7,8,9};
        for(int i=2; i<=n; ++i) {
            vector<int> a;
            for(auto& j: res) {
                if(j%10 + k < 10) a.push_back(j*10 + j%10 + k);
                if(k > 0 and j%10 - k >= 0) a.push_back(j*10 + j%10 - k);
            }
            res = a;
        }
        return res;
    }
};