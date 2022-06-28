class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int> mp;
        for(auto i: s) mp[i]++;
        vector<int> a;
        for(auto i: mp) a.push_back(i.second);
        sort(a.begin(), a.end());
        int n = a.size(), res = 0;
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
};