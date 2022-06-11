class Solution {
public:
    int minOperations(vector<int>& a, int x) {
        int n = a.size(), sum = 0, cnt = INT_MIN, k = accumulate(a.begin(), a.end(), 0) - x;
        if(k == 0) return n;
        map<int,int> mp;
        mp.insert({0,-1});
        for(int i=0; i<n; ++i) {
            sum += a[i];
            if(mp.find(sum - k) != mp.end()) {
                cnt = max(cnt, i - mp.find(sum - k)->second);
            }
            mp.insert({sum, i});
        }
        return (cnt == INT_MIN ? -1 : n - cnt);
    }
};