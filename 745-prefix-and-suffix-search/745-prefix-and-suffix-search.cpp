class WordFilter {
    unordered_map<string,unordered_map<string,int>> mp;
    unordered_map<string,int> mp2;
public:
    WordFilter(vector<string>& w) {
        int n = w.size();
        for(int i=n-1; ~i; --i) {
            int n2 = w[i].size();
            if(!mp2.count(w[i])) { 
                mp2[w[i]]++;
                string pre = "";
                for(int j=0; j < n2; ++j) {
                    pre += w[i][j];
                    string suf = "";
                    for(int k = n2-1; ~k; --k) {
                        suf = w[i][k] + suf;
                        if(!mp.count(pre))
                            mp[pre][suf] = i;
                        else if(!mp[pre].count(suf))
                            mp[pre][suf] = i;
                    }
                }
            }
        }
    }
    
    int f(string pre, string suf) {
        if(mp.count(pre) and mp[pre].count(suf))
            return mp[pre][suf];
        return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */