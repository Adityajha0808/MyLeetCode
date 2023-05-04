//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int dp(int idx,int d,vector<vector<int>> &ranges,vector<vector<int>> &memo){
        if(idx>=ranges.size() or d>1) return 0;
        if(memo[idx][d]!=-1) return memo[idx][d];
        int ans=dp(idx+1,d,ranges,memo);
        int new_idx=1e9,l=idx+1,r=ranges.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(ranges[mid][0]>=ranges[idx][1]){
                new_idx=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        ans=max(ans,dp(new_idx,d+1,ranges,memo)+ranges[idx][2]);
        return memo[idx][d]=ans;
    }
    
    int maxCoins(int n,vector<vector<int>> &ranges){
        sort(ranges.begin(),ranges.end());
        vector<vector<int>> memo(n+5,vector<int>(2,-1));
        return dp(0,0,ranges,memo);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> a(n,vector<int>(3));
        for(int i=0;i<n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
        }
        Solution ob;
        cout<<ob.maxCoins(n,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends