class Solution {
public:
    bool isHappy(int n) {
        int temp = 100;
        while(temp) {
            int r, sum = 0;
            while(n!=0) {
               r = n%10;
               sum += r*r;
               n = n/10;
            }
            n = sum;
            if(n == 1) return true;
            temp--;
        }
        return false;
    }
};