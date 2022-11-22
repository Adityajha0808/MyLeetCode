//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int countTriplets(vector<int> a) {
	    int n = a.size(), res = 0;
	    for(int i=1; i<n-1; ++i) {
	        int cnt1 = 0;
	        for(int j=i-1; ~j; --j)
	            if(a[j] < a[i])
	                cnt1++;
	        int cnt2 = 0;
	        for(int j=i+1; j<n; ++j)
	            if(a[j] > a[i])
	                cnt2++;
	        res += (cnt1 * cnt2);
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
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		int ans = ob.countTriplets(nums);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends