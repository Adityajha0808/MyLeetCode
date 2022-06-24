class Solution {
public:
    bool isPossible(vector<int>& a) {
        int n = a.size();
        priority_queue<int> pq(a.begin(), a.end());
        long long sum = 0;
        for(auto i: a) sum += i;
        int x;
        while(true) {
            x = pq.top();
            pq.pop();
            sum -= x;
            if(x == 1 or sum == 1) return true;
            if(x < sum or sum == 0 or x%sum == 0) return false;
            x %= sum;
            sum += x;
            pq.push(x);
        }
    }
};