//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    using ll = long long;
    int mod = 1e9 + 7;
    
    int findCatalan(int n) {
        vector<ll> dp(n+1, 1);
        for(int i=2; i<=n; ++i) {
            dp[i] = 0;
            for(int j=0; j<i; ++j) {
               dp[i] = (dp[i] + (dp[j] * dp[i-j-1]) % mod) % mod;
            }
        }
        return dp.back();
    }
};

//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends