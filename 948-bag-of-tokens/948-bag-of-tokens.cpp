class Solution {
public:
    int bagOfTokensScore(vector<int>& a, int k) {
        sort(a.begin(), a.end());
        int n = a.size(), l = 0, r = n-1, res = 0;
        while(l <= r) {
            if(a[l] > k) {
                if(l == r or res == 0) break;
                k += a[r];
                r--; res--;
            } else {
                k -= a[l];
                l++; res++;
            }
        }
        return res;
    }
};

// 55 71 82
// 54