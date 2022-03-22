class Solution {
public:
    string getSmallestString(int n, int k) {
        string s(n, ' ');
        for(int i=n-1; ~i; --i) {
            if(k - i > 26) {
                s[i] = 'z';
                k -= 26;
            }
            else {
                s[i] = (char)('a' + k-i-1);
                k = i;
            }
        }
        return s;
    }
};