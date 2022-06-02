class Solution {
public:
    void subsetsUtil(vector<int>& a, vector<vector<int>>& res, vector<int>& subset, int index) {
       res.push_back(subset);
       for(int i = index; i < a.size(); i++) {
          subset.push_back(a[i]);
          subsetsUtil(a, res, subset, i + 1);
          subset.pop_back();
       }
       return;
    }    
    vector<vector<int>> subsets(vector<int>& a) {
       vector<int> subset;
       vector<vector<int>> res;
       int index = 0;
       subsetsUtil(a, res, subset, index);
       return res;
    }   
    int countMaxOrSubsets(vector<int>& a) {
        int n = a.size(), res = 0, count = 0;
        for(int i=0; i<n; ++i) res |= a[i];
        vector<vector<int>> v = subsets(a);
        for(int i=0; i<v.size(); ++i) {
            int get = 0;
            for(int j=0; j<v[i].size(); ++j) {
                get |= v[i][j];
            }
            if(get == res) count++;
        }
        return count;
    }
};