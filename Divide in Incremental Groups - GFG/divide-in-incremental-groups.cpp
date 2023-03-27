//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int func(int pos, int p, int l, int k, vector<vector<vector<int>>>& dp) {
        if(pos == k) return (l ? 0 : 1);
        if(l == 0) return 0;
        if(dp[pos][p][l] != -1) return dp[pos][p][l];
        int res = 0;
        for(int i=p; i<=l; ++i)
            res += func(pos+1, i, l-i, k, dp);
        return dp[pos][p][l] = res;
    }
    
    int countWaystoDivide(int n, int k) {
        vector<vector<vector<int>>> dp(k+1, vector<vector<int>> (n+1, vector<int> (n+1, -1)));
        return func(0, 1, n, k, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        Solution ob;
        cout << ob.countWaystoDivide(N, K) << endl;
    }
}
// } Driver Code Ends