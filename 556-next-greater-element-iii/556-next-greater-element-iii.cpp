class Solution {
public:
    int nextGreaterElement(int num) {
        string s = to_string(num);
        string x = s;
        sort(x.begin(), x.end(), greater<char>());
        if(x == s) return -1;
        int n = s.size();
        next_permutation(s.begin(), s.end());
        long long a = stoll(s);
        if(a > INT_MAX) return -1;
        return a;
    }
};