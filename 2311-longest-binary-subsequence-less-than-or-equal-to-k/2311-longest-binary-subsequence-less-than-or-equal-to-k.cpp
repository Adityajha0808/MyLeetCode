class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size(), cnt = 0, m = 0;
        string res = "";
        for(int i = n-1; ~i; --i) {
            if(s[i] == '1') {
                if(cnt > k or m >= 31) {}
                else if((cnt + (1 << m)) <= k) {
                    cnt += (1 << m);
                    res.push_back('1');
                }
            } else
            res += s[i];
            m++;
        }
        reverse(res.begin(), res.end());
        return res.size();
        
    }
};