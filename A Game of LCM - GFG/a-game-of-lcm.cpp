//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    using ll = long long;
  
    ll gcd(ll a, ll b) {
        if(b == 0) return a;
        return gcd(b, a % b);
    }

    ll lcm(int N ){
        if(N == 4) return 12;
        ll a = N * (N - 1);
        ll b = a;
        b *= (N - 2) / gcd(b, N - 2);
        b *= (N - 3) / gcd(b, N - 3);
        ll c = a, f = 0;
        for (int i = N - 2; i >= 1; i--) {
            if (gcd(c, i) == 1) {
                a *= i;
                c *= i;
                f++;
            }
            if (f == 2) break;
        }
        return max(a, b);
    }
    
    ll maxGcd(int n) {
        if(n == 4) return 12;
        return max(lcm(n), lcm(n-1));
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.maxGcd(N) << "\n";
    }
}
// } Driver Code Ends