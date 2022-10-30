//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    using ll = long long;
	ll NoOfChicks(int n) {
	    ll cnt=1ll;
	    vector<ll> expires(50,0);
	    expires[6]=1;
	    for(int i=1;i<n;i++){
	        cnt-=expires[i];
	        expires[i+6]+=2*cnt;
	        cnt+=(2*cnt);
	    }
	    return cnt;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution obj;
		long long int ans = obj.NoOfChicks(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends