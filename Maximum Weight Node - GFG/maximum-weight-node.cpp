//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
    int maxWeightCell(int n, vector<int> a) {
        int res = -1, maxm = INT_MIN;
        vector<int> w(n, 0);
        for(int i=0; i<n; ++i) {
            int src = i, dest = a[i];
            if(dest != -1) {
                w[dest] += src;
                if(maxm <= w[dest]) {
                    maxm = max(maxm, w[dest]);
                    res = dest;
                }
            }
        }
        return (maxm == INT_MIN ? 0 : res);
    }
};

//{ Driver Code Starts.
int main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      int ans=obj.maxWeightCell(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends