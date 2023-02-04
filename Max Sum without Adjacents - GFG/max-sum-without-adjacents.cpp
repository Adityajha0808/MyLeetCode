//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findMaxSum(int* a, int n) {
	    int sum1 = a[0], sum2 = 0, tmp;
        for(int i=1; i<n; ++i) {
            tmp = max(sum1, sum2);
            sum1 = sum2 + a[i];
            sum2 = tmp;
        }
        return max(sum1, sum2);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends