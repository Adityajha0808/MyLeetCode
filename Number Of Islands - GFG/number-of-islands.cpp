//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int p[100000];
    int find(int x)
    {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }
    int index(int x, int y, int m)
    {
        return x * m + y;
    }
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        if (operators.empty())
            return {};

        vector<int> res;
        unordered_set<int> nodes;
        int s = operators.size();
        unordered_set<int> current;
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int total = 0;
        
        for(auto op : operators){
            int pos = index(op[0], op[1], m);
            nodes.insert(pos);
            if (current.count(pos))
            {
                res.push_back(total);
                continue;
            }
            total++;
            p[pos] = pos;
            for (int j = 0; j < 4; j++)
            {
                int nx = op[0] + dx[j];
                int ny = op[1] + dy[j];
                if (!(nx >= 0 && nx < n && ny >= 0 && ny < m)) 
                    continue;
                if (current.count(index(nx, ny, m)))
                {
                    int apos = index(op[0], op[1], m);
                    int bpos = index(nx, ny, m);
                    if (find(apos) != find(bpos))
                    {
                        p[find(apos)] = find(bpos);
                        total--;
                    }
                }
            }

            current.insert(index(op[0], op[1], m));
            res.push_back(total);
        }
        
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends