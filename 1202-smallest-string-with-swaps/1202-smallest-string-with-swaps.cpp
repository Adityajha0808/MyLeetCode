class Solution {
private:
    static const int N = 100001;
    vector<int> adj[N];
    bool visited[N];
public:
    void dfs(string &s, int i, vector<char> &ch, vector<int> &idx) {
        ch.push_back(s[i]);
        idx.push_back(i);
        visited[i] = 1;
        for(auto j: adj[i])
            if(!visited[j])
                dfs(s, j, ch, idx);
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& a) {
        int n = s.size();
        for(auto i: a) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        for(int i=0; i<n; ++i) {
            if(!visited[i]) {
                vector<char> ch;
                vector<int> idx;
                dfs(s, i, ch, idx);
                sort(ch.begin(), ch.end());
                sort(idx.begin(), idx.end());
                for(int j=0; j<ch.size(); ++j)
                    s[idx[j]] = ch[j];
            }
        }
        return s;
    }
};