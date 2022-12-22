//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    using ll = long long;
    ll findSubarray(vector<ll>& a, int n) {
        ll sum = 0, cnt = 0; 
        unordered_map<ll,ll> mp;
        for(auto& i: a) {
            sum += i;
            if(sum == 0) cnt++;
            if(mp[sum]) cnt += mp[sum];
            mp[sum]++; 
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; //input size of array
       
        vector<long long int> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}
// } Driver Code Ends