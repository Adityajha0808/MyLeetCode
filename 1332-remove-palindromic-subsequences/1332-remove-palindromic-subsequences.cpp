class Solution {
public:
    bool ispal(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        return s == t;
    }
    int removePalindromeSub(string s) {
        return ispal(s) ? 1 : 2;
    }
};