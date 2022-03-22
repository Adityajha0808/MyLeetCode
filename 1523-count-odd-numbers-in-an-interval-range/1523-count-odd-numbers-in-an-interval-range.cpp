class Solution {
public:
    int countOdds(int low, int high) {
        int diff = high - low, res = diff/2;
        if(high%2 or low%2) res++;
        return res;
    }
};