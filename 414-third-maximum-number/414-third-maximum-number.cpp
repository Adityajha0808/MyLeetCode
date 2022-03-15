class Solution {
public:
    int thirdMax(vector<int>& a) {
        int n = a.size();
        sort(a.begin(), a.end(), greater<int>());
        int cnt = 1;
        for(int i=1; i<n; ++i) {
            if(a[i] == a[i-1]) continue;
            cnt++;
            if(cnt == 3) return a[i];
        }
        return a[0];
    }
};