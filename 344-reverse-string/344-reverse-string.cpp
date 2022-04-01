class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int x = 0, y = n-1;
        for(int i=0; i<n/2; i++) {
            swap(s[x], s[y]);
            x++;
            y--;
        }
    }
};