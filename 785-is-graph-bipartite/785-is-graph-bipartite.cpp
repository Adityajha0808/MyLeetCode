class Solution {
private:
    vector<bool> visited;
    vector<int> c;
public:
    Solution() : visited(100, false), c(100, 0) {}
    bool dfs(int idx, int start, vector<vector<int>>& a) {
        visited[idx] = true;
        c[idx] = start;
        for(auto i: a[idx]) {
            if(visited[i]) {
                if(c[idx] == c[i])
                    return false;
            } else {
                if(!dfs(i, start^1, a))
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& a) {
        int n = a.size();
        for(int i=0; i<n; ++i)
            if(!visited[i] and !dfs(i,0,a))
                return false;
        return true;
    }
};