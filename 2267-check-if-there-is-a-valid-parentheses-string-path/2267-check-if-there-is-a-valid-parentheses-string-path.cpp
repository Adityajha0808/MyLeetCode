class Solution {
public:
    int dp[100][100][101];
    bool func(int x,int y,vector<vector<char> >&grid,int all){
        if(x==grid.size()-1 and y==grid[0].size()-1) {
            if(all==-1) return false;
            int add=(grid[x][y]=='('?1:-1);
            if(all+add==0) return true;
            return false;
        }
        if(all<0) return false;
        if(all>100) return false;
        if(dp[x][y][all]!=-1) return dp[x][y][all];
        bool ans = false, ans2 = false;
        if(x+1<grid.size()) {
            int add=(grid[x][y]=='('?1:-1);
            ans = func(x+1,y,grid,all+add); 
        }
        if(ans) return dp[x][y][all] = true;
        if(y+1<grid[0].size()){
            int add = (grid[x][y]=='('?1:-1);
            ans = func(x,y+1,grid,all+add); 
        }
        return dp[x][y][all] = ans;
    }
    
    
    bool hasValidPath(vector<vector<char>>& grid) {
        memset(dp,-1,sizeof(dp));
        return func(0,0,grid,0);
    }
};