class Solution {
public:
    int strStr(string h, string x) {
        int m = h.size(), n = x.size(), l = 0;
        if(!n) return 0;
        while(l<=m-n) {
            if(h[l] == x[0]) {
                string temp = h.substr(l, n);
                if(temp == x) return l;
            }
            l++;
        }
        return -1;
    }
};