//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution {
public:
    using ll = long long int;
    ll largestPrimeFactor(int n) {
        ll res = 1;
        while(n%2 == 0) {
            if(2 > res) res = 2;
            n /= 2;
        }
        for(int i=3; i<=sqrt(n); i += 2) {
            while(n%i == 0) {
                if(i > res) res = i;
                n /= i;
            }
        }
        if(n > res) res = n;
        return res;
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
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends