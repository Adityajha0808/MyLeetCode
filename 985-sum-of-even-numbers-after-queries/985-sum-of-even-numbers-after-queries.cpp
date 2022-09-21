class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& a, vector<vector<int>>& q) {
        int n = q.size();
        int sum = 0;
        for(int i=0; i<a.size(); i++) {
            if(a[i]%2==0) sum += a[i];
        }
        vector<int> v;
        for(int i=0; i<n; i++) {
            if(a[q[i][1]]%2==0)  {
                if(q[i][0]%2==0) {
                    a[q[i][1]] += q[i][0];
                    sum += q[i][0];
                } else {
                    sum -= a[q[i][1]];
                    a[q[i][1]] += q[i][0];
                }
            } else {
                if(q[i][0]%2==0) {
                   a[q[i][1]] += q[i][0];
                } else {
                   a[q[i][1]] += q[i][0];
                   sum += a[q[i][1]];
                }
            }
            if(sum%2==0) v.push_back(sum);
        }
        return v;
    }
};