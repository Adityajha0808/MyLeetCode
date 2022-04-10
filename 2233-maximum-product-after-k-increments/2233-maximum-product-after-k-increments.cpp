using ll = long long;
const int mod = 1e9 + 7;

class Solution {
public:
    int maximumProduct(vector<int>& a, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto i: a) pq.push(i);
        while(k--) {
            int x = pq.top();
            pq.pop();
            pq.push(x + 1);
        }
        ll res = 1;
        while(pq.size()) {
            res *= pq.top();
            res %= mod;
            pq.pop();
        }
        return res;
    }
};