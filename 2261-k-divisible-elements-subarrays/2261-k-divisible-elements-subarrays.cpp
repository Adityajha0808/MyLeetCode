class Solution {
public:
    int countDistinct(vector<int>& a, int k, int p) {
        int n = a.size(), res = 0, cnt;
        string s;
        unordered_map<string,int> mp;
        for(int i=0; i<n; ++i) {
            cnt = 0;
            s = "";
            for(int j=i; j<n; ++j) {
                s += a[j] + '0';
                if(a[j]%p == 0) cnt++;
                if(cnt <= k and mp.find(s) == mp.end()) {
                    mp[s]++;
                    res++;
                }
                if(cnt > k) break;
            }
        }
        return res;
    }
};