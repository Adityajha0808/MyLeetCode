class Solution {
public:
    int findKthLargest(vector<int>& a, int k) {
        priority_queue<int> pq;
        for(auto i: a) pq.push(i);
        while(pq.size()) {
            if(k == 1) return pq.top();
            pq.pop();
            k--;
        }
        return pq.top();
    }
};