//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestXYDist(vector<vector<char>> a, int n, int m) {
        int res = 1e9;
        vector<vector<int>> v(n , vector<int> (m, 1e9));
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                if(a[i][j] == 'X')
                    v[i][j] = 0;
                else {
                    if(i) v[i][j] = min(v[i][j], v[i-1][j] + 1);
                    if(j) v[i][j] = min(v[i][j], v[i][j-1] + 1);
                }
            }
        }
        for(int i=n-1; ~i; --i) {
            for(int j=m-1; ~j; --j) {
                if(a[i][j] == 'X')
                    v[i][j] = 0;
                else {
                    if(i < n-1) v[i][j] = min(v[i][j], v[i+1][j] + 1);
                    if(j < m-1) v[i][j] = min(v[i][j], v[i][j+1] + 1);
                }
            }
        }
        for(int i=0; i<n; ++i)
            for(int j=0; j<m; ++j)
                if(a[i][j] == 'Y')
                    res = min(res, v[i][j]);
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        char ch;
        cin >> N >> M;

        vector<vector<char>> grid;

        for (int i = 0; i < N; i++) {
            vector<char> col;
            for (int i = 0; i < M; i++) {
                cin >> ch;
                col.push_back(ch);
            }
            grid.push_back(col);
        }

        Solution ob;
        cout << ob.shortestXYDist(grid, N, M) << endl;
    }
    return 0;
}
// } Driver Code Ends