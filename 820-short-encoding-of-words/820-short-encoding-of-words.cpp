class Solution {
public:
    int minimumLengthEncoding(vector<string>& a) {
        set<string> s;
        for(auto i: a) s.insert(i);
        for(auto i: a) {
            for(int j=1; j<i.size(); ++j) {
                s.erase(i.substr(j, i.size() - j));
            }
        }
        int res = 0;
        for(auto i: s) res += i.size() + 1;
        return res;
    }
};