class Solution {
public:
    void sortColors(vector<int>& a) {
        int n = a.size(), zeroes = 0, ones = 0, twos = 0, j = 0;
        for(int i=0; i<n; ++i) {
            if(a[i] == 0) zeroes++;
            if(a[i] == 1) ones++;
            if(a[i] == 2) twos++;
        }
        while(zeroes--) {
            a[j] = 0;
            j++;
        }
        while(ones--) {
            a[j] = 1;
            j++;
        }
        while(twos--) {
            a[j] = 2;
            j++;
        }
    }
};