class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& a) {
        int n = a.size();
        if(a[0][0] || a[n-1][n-1]) return -1;
        queue<pair<int,int>> q;
        q.push({0,0});
        vector<vector<int>> vect = {{0,1},{1,0},{1,1},{1,-1},{-1,1},{-1,-1},{0,-1},{-1,0}};
        a[0][0] = 1;
        while(!q.empty()) {
            auto curr = q.front();
            int x = curr.first, y = curr.second;
            if(x == n-1 && y == n-1) return a[x][y];
            for(auto i: vect) {
                int nx = x + i[0];
                int ny = y + i[1];
                if(nx >= 0 && nx < n && ny >= 0 && ny < n && a[nx][ny] == 0) {
                    q.push({nx,ny});
                    a[nx][ny] = a[x][y] + 1;
                }
            }
            q.pop();
        }
        return -1;
    }
};