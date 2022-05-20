class Solution {
public:
    int uniquePaths(int m, int n) {
        int x = n+m-2, y = m-1;
        double res = 1;
        for(int i=1; i<=y; ++i) {
            res = res*(x-y+i)/i;
        }
        return (int)res;
    }
};