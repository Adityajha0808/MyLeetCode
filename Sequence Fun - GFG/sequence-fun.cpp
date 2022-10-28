//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
	public:
	    using ll = long long;
		int NthTerm(int n) {
		    ll res = 1, mod = 1e9 + 7;
			for(ll i=1; i<=n; ++i) {
				res = (res*i) + 1;
				res %= mod;
			}
			return res;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution obj;
		int ans = obj.NthTerm(n);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends