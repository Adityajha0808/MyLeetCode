//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
// int maxArea(int A[], int len);

// } Driver Code Ends
//User function template for C++

using ll = long long;

ll maxArea(ll a[], int n) {
    ll l = 0, r = n-1, res = 0, minm = LLONG_MAX;
    while(l < r) {
        minm = min(a[l], a[r]);
        res = max(res, minm * (r - l));
        (a[l] > a[r]) ? r-- : l++;
    }
    return res;
}

//{ Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxArea(arr,n)<<endl;
    }
return 0;
}

// } Driver Code Ends