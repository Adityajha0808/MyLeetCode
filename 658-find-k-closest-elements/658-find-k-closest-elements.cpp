class Solution {
public:
    vector<int> findClosestElements(vector<int>& a, int k, int x) {
        vector<int>::iterator it;
        it = lower_bound(a.begin(), a.end(), x);
        a.insert(it, x);
        it = find(a.begin(), a.end(), x);
        int i = it - a.begin() - 1, j = it - a.begin() + 1;
        vector<int> res;
        while(k > 0) {
            if(i>=0 and (j>=a.size() or abs(a[i] - x) <= abs(a[j] - x))) {
                res.push_back(a[i]);
                i--;
                k--;
            }
            if(!k) break;
            if(j<a.size() and (i < 0 or abs(a[j] - x) < abs(a[i] - x))) {
                res.push_back(a[j]);
                j++;
                k--;
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};