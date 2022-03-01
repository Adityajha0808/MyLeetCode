class Solution {
public:
    vector<int> decToBinary(int n) {
        vector<int> binaryNum(32);
        int i = 0;
        while(n > 0) {
            binaryNum[i] = n % 2;
            n = n / 2;
            i++;
        }
        return binaryNum;
    }
    vector<int> countBits(int n) {
        vector<int> res;
        for(int i=0; i<=n; ++i) {
            vector<int> a = decToBinary(i);
            res.push_back(count(a.begin(), a.end(), 1));
        }
        return res;
    }
};