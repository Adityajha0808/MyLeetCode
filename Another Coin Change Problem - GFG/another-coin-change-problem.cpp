//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    bool func(int N, int K, int target, vector<int> &coins, vector<vector<int>> &dp) {
        if (K == 0 and target == 0) return true;
        if (K <= 0 or target <= 0) return false;
        if (dp[K][target] != -1) return dp[K][target];
        bool ans = false;
        for (int i = 0; i < N; i++) {
            ans |= func(N, K - 1, target - coins[i], coins, dp);
        }
        return dp[K][target] = ans;
    }
    
    bool makeChanges(int N, int K, int target, vector<int> &coins) {
        vector<vector<int>> dp(K + 5, vector<int>(target + 5, -1));
        return func(N, K, target, coins, dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int N;
        scanf("%d", &N);

        int K;
        scanf("%d", &K);

        int target;
        scanf("%d", &target);

        vector<int> coins(N);
        Array::input(coins, N);

        Solution obj;
        bool res = obj.makeChanges(N, K, target, coins);

        cout << res << endl;
    }
}

// } Driver Code Ends