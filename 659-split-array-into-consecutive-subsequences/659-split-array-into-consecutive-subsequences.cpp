class Solution {
public:
    bool isPossible(vector<int>& a) {
        unordered_map<int,int> mp1, mp2;
        for(auto i: a) mp1[i]++;
        for(auto i: a) {
            if(!mp1[i]) continue;
            mp1[i]--;
            if(mp2[i-1] > 0) {
                mp2[i-1]--;
                mp2[i]++;
            } else if(mp1[i+1] and mp1[i+2]) {
                mp1[i+1]--;
                mp1[i+2]--;
                mp2[i+2]++;
            } else
                return false;
        }
        return true;
    }
};