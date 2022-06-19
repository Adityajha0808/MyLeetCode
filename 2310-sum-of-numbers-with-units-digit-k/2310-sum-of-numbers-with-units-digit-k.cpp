class Solution {
public:
    bool check(int n, int k) {
        string s = to_string(n);
        if(s.back() == k + '0') return true;
        return false;
    }
    int minimumNumbers(int n, int k) {
        if(n == 0) return 0;
        if(check(n, k)) return 1;
        if(k == 0 or (n%2 and k%2 == 0)) return -1;
        int cnt = 0;
        while(true) {
            if(n < k) return -1;
            if(check(n, k)) return cnt + 1;
            n -= k;
            cnt++;
        }
        return -1;
    }
};