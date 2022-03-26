class Solution {
public:
    double findMedianSortedArrays(vector<int>& a1, vector<int>& a2) {
        int n = a1.size(), m = a2.size();
        for(auto i: a2) a1.push_back(i);
        sort(a1.begin(), a1.end());
        return ((m+n)%2 ? (double)a1[(m+n)/2] : (double)(a1[(m+n)/2] + a1[(m+n)/2 - 1])/2);
    }
};