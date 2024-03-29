//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int mod = 1e9 + 7;
    int nCr(int n, int r) {
        vector<int> dp(r+1, 0);
        dp[0] = 1;
    	for(int i=1; i<=n; ++i)
    		for(int j=min(i, r); ~j; --j)
    			dp[j] = (dp[j] + dp[j-1]) % mod;
    	return dp[r]%mod;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends