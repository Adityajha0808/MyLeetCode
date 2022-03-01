class Solution {
public:
    vector<vector<int>> permute(vector<int>& a) {
        sort(a.begin(), a.end());
        vector<vector<int>> res;
        res.push_back(a);
        while(next_permutation(a.begin(), a.end())) {
            res.push_back(a);
        }
        return res;
    }
};