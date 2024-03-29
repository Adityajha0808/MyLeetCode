class Solution {
public:
    void sortColors(vector<int>& a) {
        int n = a.size(), l = 0, m = 0, r = n-1;
        while(m <= r) {
            if(a[m] == 0) {
                swap(a[m], a[l]);
                l++;
                m++;
            } else if(a[m] == 1) {
                m++;
            } else {
                swap(a[m], a[r]);
                r--;
            }
        }
    }
};