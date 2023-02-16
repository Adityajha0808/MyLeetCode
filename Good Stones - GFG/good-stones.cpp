//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution {
public:
    
    int func(vector<int>& a, vector<int>& dp, int n, int idx) {
        if(idx >= n or idx < 0) return 1;
        if(dp[idx] != -1) return dp[idx];
        dp[idx]=0;
        return dp[idx] = func(a, dp, n, a[idx] + idx);
    }
    
    int goodStones(int n, vector<int>& a) {
        vector<int> dp(n, -1);
        for(int i=0; i<n; ++i)
            func(a, dp, n, i);
        return accumulate(dp.begin(),dp.end(),0);
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
        cout<<ob.goodStones(n,arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends