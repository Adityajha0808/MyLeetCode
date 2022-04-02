class Solution {
public:
    int triangularSum(vector<int>& a) {
        while(a.size() > 1) {
            vector<int> v;
            for(int i=1; i<a.size(); ++i)
                v.push_back((a[i] + a[i-1])%10);
            a = v;
        }
        return a.back();
    }
};