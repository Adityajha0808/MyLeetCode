//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    using ll = long long;
    ll count(int a[], int n, int k) {
        vector<ll> dp(k+1, 0);
        dp[0] = 1;
        for(int i=0; i<n; ++i)
            for(int j=a[i]; j<=k; ++j)
                dp[j] += dp[j - a[i]];
        return dp[k];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends