class Solution {
public:
    int compareVersion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size(), i = 0, j = 0, num1 = 0, num2 = 0;
        while(i < n1 or j < n2) {
            while(i < n1 and s1[i] != '.') {
                num1 = num1*10 + s1[i] - '0';
                i++;
            }
            while(j < n2 and s2[j] != '.') {
                num2 = num2*10 + s2[j] - '0';
                j++;
            }
            if(num1 > num2) return 1;
            if(num2 > num1) return -1;
            num1 = 0, num2 = 0;
            i++, j++;
        }
        return 0;
    }
};