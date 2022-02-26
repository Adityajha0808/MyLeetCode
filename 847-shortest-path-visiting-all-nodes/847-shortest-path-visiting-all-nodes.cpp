class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<bool>> visited(n, vector<bool>( 1 << n, false));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i) {
            q.push({i, 1 << i});
            visited[i][1 << i] = true;
        }
        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto [node, state] = q.front();
                q.pop();
                for(auto next: graph[node]) {
                    int next_state = state | (1 << next);
                    if(next_state == (1 << n) - 1) return steps + 1;
                    if(!visited[next][next_state]) {
                        q.push({next, next_state});
                        visited[next][next_state] = true;
                    }
                }
            }
            steps++;
        }
        return 0;
    }
};