class Solution {
public:
    vector<vector<int>> res;
    void func(vector<int> &a, int n, int x, int idx) {
        if(n < 0 or x < 0) return;
        if(n == 0 and x == 0) {
            res.push_back(a);
            return;
        }
        for(int i=idx; i<10; ++i) {
            a.push_back(i);
            func(a, n-1, x-i, i+1);
            a.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int n, int x) {
        vector<int> a;
        func(a, n, x, 1);
        return res;
    }
};