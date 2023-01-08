//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    using ll = long long;
    ll countPairs(int n, int a[], int k) {
        ll res = 0;
        unordered_map<int,int> mp;
        for(int i=0; i<n; ++i) {
            auto it = mp.find((a[i] + k)%k);
            if(it != mp.end())
                res += it->second;
            mp[(a[i] + k)%k]++;
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin>>n;
        
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        
        cin>>k;

        Solution ob;
        cout << ob.countPairs(n,arr,k) << endl;
    }
    return 0;
}
// } Driver Code Ends