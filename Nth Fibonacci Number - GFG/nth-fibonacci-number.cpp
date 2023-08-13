//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    int mod = 1e9 + 7;
    int nthFibonacci(int n) {
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        for(int i=2; i<=n; ++i) dp[i] = (dp[i-1] % mod + dp[i-2] % mod) % mod;
        return dp.back();
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends