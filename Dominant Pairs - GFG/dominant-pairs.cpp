//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int dominantPairs(int n, vector<int>& a) {
        int res = 0, curr = n/2;
        sort(a.begin(), a.begin() + n/2);
        sort(a.begin() + n/2, a.end());
        for(int i=0; i<n/2; ++i) {
            while(curr < n and a[i] >= 5 * a[curr]) curr++;
            res += curr - n/2;
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.dominantPairs(n,arr)<<endl;
    }
}
// } Driver Code Ends