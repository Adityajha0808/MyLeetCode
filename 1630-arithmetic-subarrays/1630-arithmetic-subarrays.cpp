class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& a, vector<int>& l, vector<int>& r) {
        int n = a.size(), m = l.size();
        vector<bool> vect;
        for(int i=0; i<m; i++) {
            vector<int> temp(a.begin() + l[i], a.begin() + r[i] + 1);
            sort(temp.begin(), temp.end());
            int flag = 0;
            for(int j=2; j<temp.size(); j++) {
                if(temp[j] - temp[j-1] != temp[j-1] - temp[j-2]) {
                    vect.push_back(false);
                    flag = 1;
                    break;
                }
            }
            if(!flag) vect.push_back(true);
        }
        return vect;
    }
};