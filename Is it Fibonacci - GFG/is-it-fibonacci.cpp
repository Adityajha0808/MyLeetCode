//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    using ll = long long;
    ll solve(int n, int k, vector<ll> a) {
        ll sum = 0;
        vector<ll> res;
        for(auto it : a) {
            sum += it;
            res.push_back(it);
        }
        int tmp = 0;
        while(res.size() < n) {
            res.push_back(sum);
            sum -= res[tmp];
            sum += res.back();
            tmp++;
        }
        return res[n - 1];
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<long long> GeekNum(K);

        for (int i = 0; i < K; i++) cin >> GeekNum[i];

        Solution ob;
        cout << ob.solve(N, K, GeekNum) << "\n";
    }
    return 0;
}

// } Driver Code Ends