class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        for(int i=0; i<n; ++i) {
            int l = i, r = i;
            while(s[r+1]!=' ' and r+1 < n) r++;
            int sp = r+1;
            while(l < r) {
                swap(s[l],s[r]);
                l++; r--;
            }
            i = sp;
        }
        return s;
    }
};