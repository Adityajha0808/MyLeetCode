class Solution {
public:
    int findDuplicate(vector<int>& a) {
        int x = a[0], y = a[a[0]];
        while(x!=y) {
            x = a[x];
            y = a[a[y]];
        }
        y = 0;
        while(x!=y) {
            x = a[x];
            y = a[y];
        }
        return x;
    }
};