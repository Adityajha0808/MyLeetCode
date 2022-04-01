class Solution {
public:
    vector<int> sortByBits(vector<int>& a) {
        sort(a.begin(), a.end(), [](int x, int y) {
            int cnt1 = bitset<32>(x).count(), cnt2 = bitset<32>(y).count();
            if(cnt1 != cnt2) return cnt1 < cnt2;
            return x < y;
        });
        return a;
    }
};