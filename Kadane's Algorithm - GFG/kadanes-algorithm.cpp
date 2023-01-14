//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    using ll = long long;
    ll maxSubarraySum(int a[], int n){
        ll res = INT_MIN, curr = 0;
        for(int i=0; i<n; ++i) {
            curr += a[i];
            res = max(res, curr);
            if(curr < 0) curr = 0;
        }
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

// } Driver Code Ends