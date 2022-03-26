class Solution {
public:
    int largestPerimeter(vector<int>& a) {
        int n = a.size();
        sort(a.begin(), a.end());
        int x = a[n-1], y = a[n-2], z = a[n-3], i = n-4;
        while(x >= y + z or y >= x + z) {
            if(x >= y + z) {
                x = y;
                y = z;
                if(i >= 0) {
                    z = a[i];
                    i--;
                } else return 0;
            }
            if(y >= x + z) {
                y = z;
                if(i >= 0) {
                    z = a[i];
                    i--;
                } else return 0;
            }
        }
        return x + y + z;
    }
};