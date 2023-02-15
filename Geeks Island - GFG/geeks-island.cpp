//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    void func(vector<vector<int>>& a, vector<vector<bool>>& v, int i, int j, int n, int m) {
        if(i < 0 or j < 0 or i >= n or j >= m or v[i][j]) return;
        v[i][j] = true;
        if(i > 0 and !v[i-1][j] and a[i-1][j] >= a[i][j]) func(a, v, i-1, j, n, m);
        if(i < n-1 and !v[i+1][j] and a[i+1][j] >= a[i][j]) func(a, v, i+1, j, n, m);
        if(j > 0 and !v[i][j-1] and a[i][j-1] >= a[i][j]) func(a, v, i, j-1, n, m);
        if(j < m-1 and !v[i][j+1] and a[i][j+1] >= a[i][j]) func(a, v, i, j+1, n, m);
    }
    
    int water_flow(vector<vector<int>>& a, int n, int m) {
        vector<vector<bool>> x(n, vector<bool>(m, false)), y(n, vector<bool>(m, false));
        for(int i=0; i<n; ++i) func(a, x, i, 0, n, m);
        for(int i=0; i<m; ++i) func(a, x, 0, i, n, m);
        for(int i=0; i<n; ++i) func(a, y, i, m-1, n, m);
        for(int i=0; i<m; ++i) func(a, y, n-1, i, n, m);
        int res = 0;
        for(int i=0; i<n; ++i)
            for(int j=0; j<m; ++j)
                if(x[i][j] and y[i][j]) res++;
        return res;
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>mat[i][j];
            }
        }
        Solution ob;
        cout << ob.water_flow(mat, n, m) << endl;
        
    }
}


// } Driver Code Ends