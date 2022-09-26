class Solution {
public:
    int func(vector<int>& a, int idx) {
        return (a[idx] == -1 or a[idx] == idx ? idx : func(a, a[idx]));
    }
    bool equationsPossible(vector<string>& eq) {
        vector<int> a('z' + 1, -1);
        for(auto& s : eq)
            if(s[1] == '=')
                a[func(a, s[0])] = func(a, s[3]);
        for(auto& s : eq)
            if(s[1] == '!' and func(a, s[0]) == func(a, s[3]))
                return false;
        return true;
    }
};