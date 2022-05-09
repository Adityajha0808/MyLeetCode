class Solution {
public:
    vector<string> letterCombinations(string s) {
        int n = s.size();
        if(!n) return {};
        vector<string> num = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}, a, res;
        for(auto i: s)
            a.push_back(num[i - '0']);
        if(n == 1) {
            for(auto i: a[0])
                res.push_back(string(1,i));
        } else if(n == 2) {
            for(auto i: a[0])
                for(auto j: a[1])
                    res.push_back(string(1,i) + j);
        } else if(n == 3) {
            for(auto i: a[0])
                for(auto j: a[1])
                    for(auto k: a[2])
                        res.push_back(string(1,i) + j + k);
        } else {
            for(auto i: a[0])
                for(auto j: a[1])
                    for(auto k: a[2])
                        for(auto l: a[3])
                            res.push_back(string(1,i) + j + k + l);
        }
        return res;
    }
};