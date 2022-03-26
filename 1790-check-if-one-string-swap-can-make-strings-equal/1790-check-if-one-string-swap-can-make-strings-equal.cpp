class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1 == s2) return true;
        int a = INT_MIN;
        int b = INT_MIN;
        for(int i=0; i<s1.length(); i++) {
            if(s1[i] == s2[i]) continue;
            if(a < 0) {
                a = i;
                continue;
            }
            if(b < 0) {
                b = i;
                continue;
            }
            return false;
        }
        return ((a>=0 && b>=0 && s1[a] == s2[b] && s2[a] == s1[b]) ? true : false);
    }
};