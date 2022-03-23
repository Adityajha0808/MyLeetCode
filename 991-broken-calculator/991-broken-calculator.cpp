class Solution {
public:
    int brokenCalc(int n, int x) {
        int res = 0;
        while(x != n) {
            if(x > n) {
                if(x%2) x++;
                else 
                    x /= 2;
                res++;
            } else
                x++, res++;
        }
        return res;
    }
};