//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution {
public:
    int findK(int a[MAX][MAX], int m, int n, int x) {
 		int res = 0, k = 0, l = 0, i;
        while(k < m and l < n) {
            for(i=l; i<n; i++) {
                res++;
                if(res == x) return a[k][i];
            }
            k++;
            for(i=k; i<m; i++) {
                res++;
                if(res == x) return a[i][n-1];
            }
            n--;
            if(k < m) {
                for(i=n-1; i>=l; i--) {
                    res++;
                    if(res == x) return a[m-1][i];
                }
                m--;
            }
            if(l < n) {
                for(i=m-1; i>=k; i--) {
                    res++;
                    if(res == x) return a[i][l];
                }
                l++;
            }
        }
        return -1;
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends