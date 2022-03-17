class Solution {
public:
    int min_ops(vector<int>& a) {
        int n = a.size(), res = 0;
        sort(a.begin(), a.end());
        for(int i=n-2; ~i; --i) {
            if(a[i] >= a[i+1]) {
                if(a[i+1] == 0) {
                    res += a[i];
                    a[i] = 0;
                    continue;
                }
                res += a[i] - a[i+1] + 1;
                a[i] = a[i+1] - 1;
            }
        }
        return res;
    }
    int minDeletions(string s) {
        set<char> st;
        for(auto i: s) st.insert(i);
        vector<int> freq;
        for(auto i: st) {
            freq.push_back(count(s.begin(), s.end(), i));
        }
        return min_ops(freq);
    }
};