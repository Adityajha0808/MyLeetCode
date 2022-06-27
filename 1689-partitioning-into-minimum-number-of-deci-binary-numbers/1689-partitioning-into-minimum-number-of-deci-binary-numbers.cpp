class Solution {
public:
    int minPartitions(string s) {
        int maxm = 0;
        for(auto i: s)
            maxm = max(maxm, i - '0');
        return maxm;
    }
};