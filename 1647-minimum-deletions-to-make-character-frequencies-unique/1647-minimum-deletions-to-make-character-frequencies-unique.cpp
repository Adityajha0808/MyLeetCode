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
        unordered_map<char,int> mp;
        for(auto i: s) mp[i]++;
        int res = 0;
        vector<int> freq;
        for(auto i: mp) freq.push_back(i.second);
        return min_ops(freq);
    }
};