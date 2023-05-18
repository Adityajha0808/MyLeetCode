//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    void func(vector<vector<int>>& a, vector<vector<bool>>& v, int x, int y, int n, int m, bool& check) {
        if(x < 0 or y < 0 or x >= n or y >= m or v[x][y] == true or a[x][y] == 0) return;
        if(x == 0 or y == 0 or x == n-1 or y == m-1)
            if(a[x][y]) check = true;
        v[x][y] = true;
        func(a, v, x+1, y, n, m, check);
        func(a, v, x, y+1, n, m, check);
        func(a, v, x-1, y, n, m, check);
        func(a, v, x, y-1, n, m, check);
    }
    
    int closedIslands(vector<vector<int>>& a, int n, int m) {
        vector<vector<bool>> v(n,vector<bool>(m, false));
        int res = 0; 
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                if((i and j and i!=n-1 and j!=m-1) and a[i][j] == 1 and v[i][j] == false) {
                    bool check = false;
                    func(a, v, i, j, n, m, check);
                    if(!check) res++;
                }
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends