class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size(), l = 0, r = n;
        vector<int> res(n+1);
        for(int i=0; i<n; ++i) {
            if(s[i] == 'I')
                res[i] = l++;
            else
                res[i] = r--;
        }
        res[n] = l;
        return res;
    }
};