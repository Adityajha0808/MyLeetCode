class Solution {
public:
    string greatestLetter(string s) {
        int n = s.size();
        vector<char> a;
        for(int i=0; i<n; ++i) {
            for(int j=1; j<n; ++j) {
                if(s[i] != s[j] and toupper(s[i]) == toupper(s[j]) and tolower(s[i]) == tolower(s[j])) {
                    a.push_back(s[i]);
                    a.push_back(s[j]);
                }
            }
        }
        if(a.empty()) return "";
        char ch = 'A';
        for(auto i: a)
            ch = max(ch, i);
        ch = toupper(ch);
        string str(1, ch);
        return str;
    }
};