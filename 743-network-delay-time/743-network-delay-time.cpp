class Solution {
public:
    vector<pair<int, int>> adj[101];
    void func(vector<int>& v, int k, int n) {
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        v[k] = 0;
        while(pq.size()) {
            int time = pq.top().first, node = pq.top().second; 
            pq.pop();
            if(time > v[node]) continue;
            for(auto i: adj[node]) {
                int time2 = i.first, node2 = i.second;
                if(v[node2] > time + time2) {
                    v[node2] = time + time2;
                    pq.push({v[node2], node2});
                }
            }
        }
    }
    int networkDelayTime(vector<vector<int>>& a, int n, int k) {
        for(auto i: a) adj[i[0]].push_back({i[2], i[1]});
        vector<int> v(n+1, INT_MAX);
        func(v, k, n);
        int res = *max_element(v.begin()+1, v.end());
        return (res == INT_MAX ? -1 : res);
    }
};