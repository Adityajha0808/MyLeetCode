class Solution {
public:
    bool digitCount(string s) {
        vector<int> a(10,0);
        for(auto i: s) a[i - '0']++;
        string x = "";
        for(auto i: a) x.push_back((char)(i + '0'));
        while(s.size() != 10) s.push_back('0');
        return s == x;
    }
};