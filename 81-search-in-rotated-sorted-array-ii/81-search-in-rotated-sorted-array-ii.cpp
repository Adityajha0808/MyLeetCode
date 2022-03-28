class Solution {
public:
    bool search(vector<int>& a, int x) {
        int n = a.size();
        if(n == 1) return(a[0] == x ? true : false);
        int l = 0, h = n-1;
        while(l < h) {
            int mid = l + (h - l)/2;
            if(a[mid] == x) return true;
            if(a[mid] > a[h])
                (x < a[mid] and x >= a[l]) ? h = mid : l = mid+1;
            else if(a[mid] < a[h])
                (x > a[mid] and x <= a[h]) ? l = mid+1 : h = mid;
            else h--;
        }
        return a[l] == x ? true : false;
    }
};