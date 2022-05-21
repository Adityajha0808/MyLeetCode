class Solution {
public:
    string findDifferentBinaryString(vector<string>& a) {
        int n = a.size(), cnt = 0;
        string res = "", org;
        for(int i=0; i<n; ++i)
            res.push_back('0');
        org = res;
        while(true) {
            for(int i=cnt; i<=n; ++i) {
                if(find(a.begin(), a.end(), res) == a.end())
                    return res;
                if(i == n) break;
                res[i] = '1';
            }
            res = org;
            cnt++;
        }
        return "";
    }
};