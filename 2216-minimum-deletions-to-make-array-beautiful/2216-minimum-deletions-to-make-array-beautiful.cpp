class Solution {
public:
    int minDeletion(vector<int>& a) {
        vector<int> v;
        int j = 0;
        v.push_back(a[0]);
        for(auto i: a) {
            if(j%2 or v[j] != i) {
                v.push_back(i);
                j++;
            }  
        }
       return a.size() - v.size() + (v.size()%2 ? 1 : 0);
    }
};