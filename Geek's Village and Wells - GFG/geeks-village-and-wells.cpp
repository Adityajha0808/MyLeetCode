//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<vector<int>> chefAndWells(int n,int m,vector<vector<char>> &c) {
        vector<vector<int>> res(n,vector<int>(m,1e9));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(c[i][j]=='W'){
                    q.push({i,j});
                    res[i][j]=0;
                }
            }
        }
        int dx[4]={0,0,-1,1};
        int dy[4]={-1,1,0,0};
        while(q.size()){
            auto cur=q.front();
            q.pop();
            int curx=cur.first,cury=cur.second;
            for(int i=0;i<4;i++){
                int x=curx+dx[i],y=cury+dy[i];
                if(x>=0 and x<n and y>=0 and y<m and c[x][y]!='N' and res[x][y]>res[curx][cury]+1){
                    q.push({x,y});res[x][y]=res[curx][cury]+1;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(c[i][j]=='.') res[i][j]=0;
                else if(res[i][j]==1e9 and c[i][j]!='N') res[i][j]=-1;
                else if(res[i][j]==1e9 and c[i][j]!='H') res[i][j]=0;
                else res[i][j]*=2;
            }
        }
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
        vector<vector<char>> c(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>c[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> res=ob.chefAndWells(n,m,c);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
// } Driver Code Ends