class Solution {
public:
    bool checkPossibility(vector<int>& a) {
        int n = a.size(), limit = a[0], cnt = 0;
        for(int i=1; i<n; ++i) {
            if(a[i] < limit) {
                if(i<2 or a[i-2] <= a[i]) {
                    limit = a[i];
                }
                if(++cnt == 2)
                    return false;
            } else
                limit = a[i];
        }
        return true;
    }
};