//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isValid(int x, int y, int n, int m) {
        return x >= 0 and x < n and y >= 0 and y < m;
    }

    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        queue<pair<int, int>> q;

        q.push(source);
        dist[source.first][source.second] = 0;
        while (!q.empty()) {
            pair<int, int> currentCell = q.front();
            q.pop();
            int currentX = currentCell.first;
            int currentY = currentCell.second;
            if (currentCell == destination) {
                return dist[currentX][currentY];
            }
            for (int i = 0; i < 4; i++) {
                int nextX = currentX + dx[i];
                int nextY = currentY + dy[i];
                if (isValid(nextX, nextY, n, m) && grid[nextX][nextY] &&
                    dist[nextX][nextY] == INT_MAX) {
                    q.push({nextX, nextY});
                    dist[nextX][nextY] = dist[currentX][currentY] + 1;
                }
            }
        }

        return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends