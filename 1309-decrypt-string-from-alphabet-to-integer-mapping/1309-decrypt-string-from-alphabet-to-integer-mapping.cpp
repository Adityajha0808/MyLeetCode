class Solution {
public:
    string freqAlphabets(string s) {
        int n = s.size();
        string res;
        for(int i=0; i<n; ++i) {
            if(s[i] == '#') {
                int x = 10 * (s[i-2] - '0') + (s[i-1] - '0');
                res.pop_back();
                res.pop_back();
                res.push_back((char)('a' + x - 1));
            } else
                res.push_back(s[i]);
        }
        n = res.size();
        s.clear();
        for(int i=0; i<n; ++i) {
            if(res[i] == '1' and i<n-1 and res[i+1] == '0') s.push_back('j');
            else if(isdigit(res[i])) s.push_back((char)('a' + (res[i] - '0') - 1));
            else s.push_back(res[i]);
        }
        return s;
    }
};