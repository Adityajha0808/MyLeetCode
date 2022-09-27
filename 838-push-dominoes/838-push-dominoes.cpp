class Solution {
public:
    string pushDominoes(string s) {
        int n = s.size(), x = 0;
        vector<int> a(n, 0);
        for(int i=0; i<n; ++i) {
            if(s[i] == 'R')
                x = n;
            else if(s[i] == 'L')
                x = 0;
            else
                x = max(x-1, 0);
            a[i] += x;
        }
        x = 0;
        for(int i=n-1; ~i; --i) {
            if(s[i] == 'L')
                x = n;
            else if(s[i] == 'R')
                x = 0;
            else x = max(x-1, 0);
            a[i] -= x;
        }
        string res = "";
        for(auto& i: a)
            res.push_back(i > 0 ? 'R' : (i < 0 ? 'L' : '.'));
        return res;
    }
};