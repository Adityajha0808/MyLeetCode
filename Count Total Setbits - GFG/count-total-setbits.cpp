//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    using ll = long long;
    ll countBits(ll n) {
        ll res = 0, x, y, z;
        for(int i=0; i<31; ++i) {
            x = 1 << i;
            y = (n+1)/(x*2) * x;
            z = (n+1)%(x*2) - x;
            res += y + max(z, 0LL);
        }
        return res;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        long long N;
        scanf("%lld",&N);
        
        Solution obj;
        long long res = obj.countBits(N);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends