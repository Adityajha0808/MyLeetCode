class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& a) {
        unordered_map<int,int> win, lose;
        for(auto i: a) win[i[0]]++, lose[i[1]]++;
        vector<int> w, l;
        for(auto i: win)
            if(lose.find(i.first) == lose.end())
                w.push_back(i.first);
        for(auto i: lose)
            if(i.second == 1)
                l.push_back(i.first);
        vector<vector<int>> res;
        sort(w.begin(), w.end());
        sort(l.begin(), l.end());
        res.push_back(w);
        res.push_back(l);
        return res;
    }
};