using ll = long long;
class Solution {
public:
    ll minSumSquareDiff(vector<int>& a1, vector<int>& a2, int k1, int k2) {
        int n = a1.size(), k = k1 + k2;
        unordered_map<int, int> mp;
        for(int i=0; i<n; ++i) {
            int tmp = abs(a1[i] - a2[i]);
            if(tmp == 0) continue; 
            mp[tmp]++;
        }
        priority_queue<pair<int, int>> pq;
        for(auto i: mp) {
            pq.push({i.first, i.second});
        }
        while(pq.size() and k > 0) {
            auto tmp = pq.top();
            pq.pop();
            int minus = min(k, tmp.second);
            k -= minus;
            tmp.second -= minus;
            if(pq.size()) {
                if(tmp.second) pq.push(tmp);
                if(pq.top().first == tmp.first - 1) {
                    auto tmp2 = pq.top();
                    pq.pop();
                    tmp2.second += minus;
                    pq.push(tmp2);
                } else if(tmp.first - 1 > 0)
                    pq.push({tmp.first - 1, minus});
            } else {
                if(tmp.first - 1 > 0)
                    pq.push({tmp.first - 1, minus});
                if(tmp.second) pq.push(tmp);
            }
        }
        ll res = 0;
        while(pq.size()) {
            res += ((ll)pq.top().first * pq.top().first * pq.top().second);
            pq.pop();
        }
        return res;
    }
};