class Solution {
public:
    int minMaxGame(vector<int>& a) {
        int n = a.size();
        if(n == 1) return a[0];
        vector<int> v;
        bool flag = false;
        for(int i=0; i<n-1; i+=2) {
            v.push_back((flag ? max(a[i], a[i+1]) : min(a[i], a[i+1])));
            flag = !flag;
        }
        return minMaxGame(v);
    }
};