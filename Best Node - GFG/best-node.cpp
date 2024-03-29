//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
  
    void dfs(int u,int p,vector<int> adj[],vector<vector<long long>> &ans,vector<int> &a,vector<bool> &lef)
    {
		bool islef = 1;
        for(int v:adj[u])
        {
            if(p!=v)
            {
				islef = 0;
                ans[v][0] = max({ans[v][0],ans[u][1]+a[v]});
                ans[v][1] = max({ans[v][1],ans[u][0]-a[v]});
                dfs(v,u,adj,ans,a,lef);
            }
        }
        lef[u] = islef;
    }
    
    long long bestNode(int n, vector<int> &A, vector<int> &P) {
        vector<vector<long long>> v(n ,vector<long long>(2,-1e18));
        for(int i = 0; i<n; i++)
        {
            v[i][0] = A[i];
        }
        
        for(int &i:P)i--;
        vector<int> adj[n];
        for(int i = 1; i<n; i++)
        {
            adj[i].push_back(P[i]);
            adj[P[i]].push_back(i);
        }
       
        vector<bool> lef(n,0);
        dfs(0,-1,adj,v,A,lef);
        long long ans = -1e18;
        for(int i = 0; i<n; i++)
        {
			if(lef[i])
            ans = max({ans,v[i][0],v[i][1]});
        }
        return ans;
    }

};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        
        vector<int> P(N);
        Array::input(P,N);
        
        Solution obj;
        long long res = obj.bestNode(N, A, P);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends