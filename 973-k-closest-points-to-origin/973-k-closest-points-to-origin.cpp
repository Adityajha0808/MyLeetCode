typedef tuple<double long, int, int> tup;
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& a, int k) {
        int n = a.size();
        priority_queue<tup, vector<tup>, greater<tup>> pq;
        for(int i=0; i<n; ++i) {
            int x = a[i][0], y = a[i][1];
            x = x*x; y = y*y;
            double long d = sqrt(x + y);
            pq.push({d, a[i][0], a[i][1]});
        }
        vector<vector<int>> res;
        while(k--) {
            tuple<double long, int, int> top = pq.top();
            res.push_back({get<1>(top), get<2>(top)});
            pq.pop();
        }
        return res;
    }
};