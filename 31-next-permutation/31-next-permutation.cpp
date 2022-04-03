class Solution {
public:
    void nextPermutation(vector<int>& a) {
        int n = a.size(), p, l;
        for(p=n-1; p>0; --p) {
            if(a[p] > a[p-1]) break;
        }
        p--;
        if(p < 0) {
            reverse(a.begin(), a.end());
            return;
        }
        for(l = n - 1; l > p; l--)
            if(a[l] > a[p])
                break; 
    	swap(a[p], a[l]);
    	reverse(a.begin() + p + 1, a.end());
    }
};