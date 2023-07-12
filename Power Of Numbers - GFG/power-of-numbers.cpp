//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    using ll = long long;
    int mod = 1000000007;

    ll func(ll n, ll r) {
        if(n == 0) return 0;
        if(r == 0) return 1;
        ll tmp;
        if(r%2) {
            tmp = n%mod;
            tmp = (tmp * func(n, r-1)%mod)%mod;
        } else {
            tmp = func(n, r/2);
            tmp = (tmp*tmp)%mod;
        }
        return ((tmp+mod)%mod);
    }

    ll power(int n,int r) {
        return func(n, r)%mod;
    }

};

//{ Driver Code Starts.

// compute reverse of a number 
long long rev(long long n)
{
    long long rev_num = 0;
     while(n > 0) 
      { 
        rev_num = rev_num*10 + n%10; 
        n = n/10; 
      } 
      return rev_num;
}




int main()
{
    int T;
    cin>>T;//testcases
    
    while(T--)
    {
        long long N;
        cin>>N;//input N
        
        long long R = 0; 
        
        // reverse the given number n
        R = rev(N);
        Solution ob;
        //power of the number to it's reverse
        long long ans =ob.power(N,R);
        cout << ans<<endl;
    }
}
// } Driver Code Ends