class Solution {
public:
    vector<string> letterCombinations(string s) {
        int n = s.size();
        if(n == 0) return {};
        vector<string> a, res;
        for(int i=0; i<n; ++i) {
            if(s[i] == '2') a.push_back("abc");
            if(s[i] == '3') a.push_back("def");
            if(s[i] == '4') a.push_back("ghi");
            if(s[i] == '5') a.push_back("jkl");
            if(s[i] == '6') a.push_back("mno");
            if(s[i] == '7') a.push_back("pqrs");
            if(s[i] == '8') a.push_back("tuv");
            if(s[i] == '9') a.push_back("wxyz");
        }
        if(n == 1) {
            for(auto i: a[0]) {
                string curr = "";
                curr.push_back(i);
                res.push_back(curr);
            }
        } else if(n == 2) {
            for(auto i: a[0]) {
                for(auto j: a[1]) {
                    string curr = "";
                    curr.push_back(i);
                    curr.push_back(j);
                    res.push_back(curr);
                }
            }
        } else if(n == 3) {
            for(auto i: a[0]) {
                for(auto j: a[1]) {
                    for(auto k: a[2]) {
                        string curr = "";
                        curr.push_back(i);
                        curr.push_back(j);
                        curr.push_back(k);
                        res.push_back(curr);
                    }
                }
            }
        } else {
            for(auto i: a[0]) {
                for(auto j: a[1]) {
                    for(auto k: a[2]) {
                        for(auto l: a[3]) {
                            string curr = "";
                            curr.push_back(i);
                            curr.push_back(j);
                            curr.push_back(k);
                            curr.push_back(l);
                            res.push_back(curr);
                        }
                    }
                }
            }
        }
        return res;
    }
};