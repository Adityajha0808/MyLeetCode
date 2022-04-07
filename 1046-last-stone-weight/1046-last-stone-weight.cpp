class Solution {
public:
    int lastStoneWeight(vector<int>& a) {
        priority_queue<int> pq;
        for(auto i: a) pq.push(i);
        while(pq.size() > 1) {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            if(x == y) continue;
            else pq.push(x-y);
        }
        return (pq.size() ? pq.top() : 0);
    }
};