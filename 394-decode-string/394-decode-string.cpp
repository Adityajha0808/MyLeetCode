class Solution {
public:
    string func(string s, int& pos) {
        int num = 0;
        string res = "";
        for(;pos<s.size(); ++pos) {
            char curr = s[pos];
            if(curr == '[') {
                string currStr = func(s, ++pos);
                for(;num>0; --num) {
                    res += currStr;
                }
            } else if (curr >= '0' && curr <='9') {
                num = num*10 + curr - '0';
            } else if (curr == ']') {
                return res;
            } else {
                res += curr;
            }
        }
        return res;
    }
    string decodeString(string s) {
        int i = 0;
        return func(s, i);
    }
};