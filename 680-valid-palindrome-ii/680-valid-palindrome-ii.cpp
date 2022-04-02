class Solution {
public:
    bool isPal(string s) {
        string x = s;
        reverse(s.begin(), s.end());
        return s == x;
    }
    bool validPalindrome(string s) {
        int n = s.size(), l = 0, r = n-1;
        while(l < r) {
            if(s[l] != s[r]) {
                return (isPal(s.substr(l, r-l)) or isPal(s.substr(l+1, r-l)));
            }
            l++, r--;
        }
        return true;
    }
};