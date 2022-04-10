class Solution {
public:
    int largestInteger(int n) {
        string s = to_string(n);
        vector<int> even, odd;
        for(auto i: s) {
            if(i%2) odd.push_back(i);
            else even.push_back(i);
        }
        sort(odd.begin(), odd.end(), greater<int>());
        sort(even.begin(), even.end(), greater<int>());
        string res = "";
        int e = 0, o = 0;
        for(auto i: s) {
            if(i%2) {
                res.push_back(odd[o]);
                o++;
            } else {
                res.push_back(even[e]);
                e++;
            }
        }
        return stoi(res);
    }
};