class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = s.length(), maxm = 0;
        vector<int> v(256,-1);
        int i=0, j=0;
        while(j<l) {
            if(v[s[j]!=-1]) {
                i = max(v[s[j]]+1, i);
            }
            v[s[j]] = j;
            maxm = max(maxm, j-i+1);
            j++;
        }
        return maxm;
    }
};