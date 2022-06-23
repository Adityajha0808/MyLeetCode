class Solution {
public:
    int scheduleCourse(vector<vector<int>>& a) {
        sort(a.begin(), a.end(), [](vector<int>& x, vector<int>& y) {
            return x[1] < y[1];
        });
        priority_queue<int> pq;
        int time = 0;
        for(auto i: a) {
            if(time + i[0] <= i[1]) {
                pq.push(i[0]);
                time += i[0];
            } else if(pq.size() and pq.top() > i[0]) {
                time += i[0] - pq.top();
                pq.pop();
                pq.push(i[0]);
            }
        }
        return pq.size();
    }
};