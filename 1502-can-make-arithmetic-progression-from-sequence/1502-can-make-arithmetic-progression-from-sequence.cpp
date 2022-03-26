class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& a) {
        sort(a.begin(), a.end());
        int d = a[1] - a[0];
        for(int i=1; i<a.size()-1; ++i) {
            if(a[i+1] - a[i] != d) return false;
        }
        return true;
    }
};