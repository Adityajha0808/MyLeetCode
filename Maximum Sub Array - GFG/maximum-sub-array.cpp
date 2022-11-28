//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> findSubarray(int a[], int n) {
	    map<int, pair<int,int>, greater<int>> mp;
	    int start = 0, end = 0, sum = a[0];
	    if(a[0] < 0) {
	        start = end = 1;
	        sum = 0;
	    }
	    for(int i=1; i<n; ++i) {
	        if(a[i] < 0) {
	            if(sum) mp.insert({sum, {start, end}});
	            start = i+1, end = i+1;
	            sum = 0;
	            continue;
	        }
	        end = i;
	        sum += a[i];
	    }
	    if(sum) mp.insert({sum, {start, end}});
	    vector<int> res;
	    int l = mp.begin()->second.first, r = mp.begin()->second.second;
	    if(mp.empty()) return {-1};
	    for(int i=l; i<=r; ++i)
	        res.push_back(a[i]);
	    return res;
	}
};

//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends