class KthLargest {
public:
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;
    KthLargest(int x, vector<int>& a) {
        k = x;
        for(auto i: a) pq.push(i);
        while(pq.size() > x) pq.pop();
    }
    int add(int n) {
        pq.push(n);
        if(pq.size() > k) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */