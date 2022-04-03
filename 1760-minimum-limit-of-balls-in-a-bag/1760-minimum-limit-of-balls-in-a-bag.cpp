class Solution {
public:
    int minimumSize(vector<int>& a, int k) {
        int l = 1, r = 1e9;
        while(l < r) {
            int mid = l + (r - l)/2, x = 0;
            for(auto i: a) x += (i-1)/mid;
            if(x > k)
                l = mid + 1;
            else
                r = mid;
        }
        return r;
    }
};