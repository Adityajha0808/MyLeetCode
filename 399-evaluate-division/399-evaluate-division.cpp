class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> adj;
    unordered_map<string, bool> visited;
    double x;
    bool dfs(string start, string end, double p) {
        if(start == end and adj.find(start) != adj.end()) {
            x = p;
            return true;
        }
        bool temp = false;
        visited[start] = true;
        for(int i = 0; i < adj[start].size(); ++i) {
            if(!visited[adj[start][i].first]) {
                temp = dfs(adj[start][i].first, end, p * adj[start][i].second);
                if(temp) break;
            }
        }
        visited[start] = false;
        return temp;       
    }
    vector<double> calcEquation(vector<vector<string>>& e, vector<double>& v, vector<vector<string>>& q) {
        int n = e.size(), m = q.size();
        vector<double> res(m, 0);
        for(int i=0; i<n; ++i) {
            adj[e[i][0]].push_back({e[i][1], v[i]});
            adj[e[i][1]].push_back({e[i][0], 1/v[i]});
            visited[e[i][0]] = false;
            visited[e[i][1]] = false;
        }
        for(int i=0; i<m; ++i) {
            x = 1;
            res[i] = (dfs(q[i][0], q[i][1], 1) ? x : -1);
        }
        return res;
    }
};