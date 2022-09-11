class Solution {
public:
    using pii = pair<int, int>;
    int mod = 1e9 + 7;
    int maxPerformance(int n, vector<int>& sp, vector<int>& ef, int k) {
        vector<pii> a;
        for(int i=0; i<n; ++i)
            a.push_back({ef[i], sp[i]});
        sort(a.begin(), a.end(), [](pii x, pii y) {
            if(x.first == y.first)
                return x.second > y.second;
            return x.first > y.first;
        });
        long long sum = 0, res = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto& i: a) {
            pq.push(i.second);
            sum += i.second;
            if(pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            res = max(res, sum * i.first);
        }
        return res%mod;
    }
};