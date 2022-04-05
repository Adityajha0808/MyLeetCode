
class Solution {
public:
    int maxArea(vector<int>& a) {
        int low = 0, high = a.size()-1, res = 0, minm;
        while(low < high) {
            minm = min(a[low], a[high]);
            res = max(res, minm*(high-low));
            (a[low] > a[high]) ? high-- : low++;
        }
        return res;
    }
};