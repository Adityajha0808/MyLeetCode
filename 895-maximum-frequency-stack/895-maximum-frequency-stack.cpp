class FreqStack {
public:
    unordered_map<int,int> mp;
    priority_queue<pair<int, pair<int, int>>> pq;
    int i = 0;
    FreqStack() {}
    
    void push(int n) {
        mp[n]++;
        i++;
        pq.push({mp[n], {i, n}});
    }
    
    int pop() {
        int n = pq.top().second.second;
        pq.pop();
        mp[n]--;
        return n;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */