class Solution {
public:
    char findTheDifference(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        int n = t.size();
        for(int i=0; i<n-1; ++i) {
            if(s[i] != t[i]) return t[i];
        }
        return t[n-1];
    }
};