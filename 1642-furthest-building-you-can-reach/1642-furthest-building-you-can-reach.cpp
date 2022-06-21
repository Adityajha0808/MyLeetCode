class Solution {
public:
    int furthestBuilding(vector<int>& a, int b, int l) {
        int n = a.size();
        priority_queue<int> pq;
        for(int i=0; i<n-1; ++i) {
            int diff = a[i+1] - a[i];
            if(diff > 0)
                pq.push(-diff);
            if(pq.size() > l) {
                b += pq.top();
                pq.pop();
            }
            if(b < 0)
                return i;
        }
        return n-1;
    }
};