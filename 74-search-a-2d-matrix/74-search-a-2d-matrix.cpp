class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int x) {
        int m = a.size(), n = a[0].size(), l = 0, r = m*n - 1;
        while(l<=r) {
            int mid = (l+r)/2;
            if(a[mid/n][mid%n] == x)
                return true;
            else if(a[mid/n][mid%n] < x)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return false;
    }
};