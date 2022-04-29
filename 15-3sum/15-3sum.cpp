class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        int n = a.size();
        vector<vector<int>> vect;
        if(n < 3) return vect;
        sort(a.begin(), a.end());
        for(int i=0; i<n; i++) {
            if(i > 0 && a[i] == a[i-1]) continue;
            int p = i + 1, q = n-1;
            while(p<q) {
               if(a[p] + a[q] + a[i] == 0) {
                   vector<int> v{a[p], a[q], a[i]};
                   vect.push_back(v);
                   v.clear();
                   while(p<q && a[p] == a[p+1]) p++;
                   while(p<q && a[q] == a[q-1]) q--;
                   p++;
                   q--;
               }
               else if(a[p] + a[q] + a[i] > 0)
                  q--;
               else
                  p++;
            }
        }
        return vect;
    }
};