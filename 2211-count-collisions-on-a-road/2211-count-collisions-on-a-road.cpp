class Solution {
public:
    int countCollisions(string s) {
        int n = s.size(), res = 0;
        for(int i=1; i<n; ++i) {
            if(s[i] == 'L' and s[i-1] == 'S') {
                res++;
                s[i] = 'S';
            } else if(s[i] == 'L' and s[i-1] == 'R') {
                res += 2;
                s[i] = 'S';
                s[i-1] = 'S';
            }
            else if(s[i] == 'S' and s[i-1] == 'R') {
                s[i-1] = 'S';
                res++;
            }
        }
        for(int i=n-2; ~i; --i) {
            if(s[i] == 'R' and s[i+1] == 'S') {
                res++;
                s[i] = 'S';
            } else if(s[i] == 'R' and s[i+1] == 'L') {
                res+=2;
                s[i] = 'S';
                s[i+1] = 'S';
            }
        }
        return res;
    }
};