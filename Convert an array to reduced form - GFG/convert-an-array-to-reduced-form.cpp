//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	void convert(int a[], int n) {
	    int v[n];
        for(int i=0; i<n; ++i)
            v[i] = a[i];
	    sort(v, v+n);
	    unordered_map<int,int> mp;
	    for(int i=0; i<n; ++i)
	        mp.insert({v[i], i});
	    for(int i=0; i<n ;++i)
	        a[i] = mp.find(a[i])->second;
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
        ob.convert(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends