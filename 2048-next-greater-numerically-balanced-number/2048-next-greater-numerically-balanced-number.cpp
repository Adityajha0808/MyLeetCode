class Solution {
public:
    bool isbal(int n) {
        vector<int> cnt(10,0);
        while(n) {
            int r = n%10;
            if(!r) return false;
            cnt[r]++;
            n /= 10;
        }
        for (int i = 1; i < 10; ++i) {
            if(cnt[i] && cnt[i] != i) return false;
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        while(true) {
            n++;
            if(isbal(n)) return n;
        }
        return -1;
    }
};