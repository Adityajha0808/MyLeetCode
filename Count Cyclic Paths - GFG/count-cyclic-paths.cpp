//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
// User function Template for C++

class Solution {   
public:
    using ll = long long;
    ll mod = 1000000007;
    
    int countPaths(int n) {
        ll l = 1l, h = 0l, l1 = 1l, h1 = 0l;
        for(int i=2; i<=n; ++i) {
            h = (3 * l1) % mod;
            l = (((2 * l1) % mod) + h1) % mod;
            l1 = l;
            h1 = h;
        }
        return h;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        
        Solution ob;
        cout << ob.countPaths(N) << endl;
    }
    return 0; 
}

// } Driver Code Ends