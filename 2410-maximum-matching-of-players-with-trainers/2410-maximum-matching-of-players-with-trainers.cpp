class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& p, vector<int>& t) {
        int n = p.size(), res = 0, c = 0;
        sort(p.begin(), p.end());
        sort(t.begin(), t.end());
        for(int i=0; i<n; ++i) {
            while(c < t.size() and p[i] > t[c]) c++;
            if(c == t.size()) break;
            if(p[i] <= t[c]) res++;
            c++;
        }
        return res;
    }
};