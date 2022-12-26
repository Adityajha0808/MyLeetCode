//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    using ll = long long;
    
    void precompute() {}
    
    ll solve(ll l, ll r){
        ll cnt = 0, i = 1;
        while(i < r) {
            ll j = i << 1;
            while(j < r) {
                ll k = j << 1;
                while(k < r) {
                    ll temp = i | j | k;
                    if(l <= temp and temp <= r)
                        cnt++;
                    k <<= 1;
                }
                j <<= 1;
            }
            i <<= 1;
        }
        return cnt;
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    Solution ob;
    ob.precompute();
    cin>>t;
    while(t--)
    {
        long long l,r;
        cin>>l>>r;
        cout << ob.solve(l, r) << endl; 
    }
    return 0;
}
// } Driver Code Ends