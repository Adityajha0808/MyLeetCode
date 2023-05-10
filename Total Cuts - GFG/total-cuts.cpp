//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int totalCuts(int n,int k, vector<int>& a) {
        int res = 0, minm = INT_MAX;
        vector<int> v = a;
        for(int i=1; i<n; ++i) v[i] = max(v[i], v[i-1]);
        for(int i=n-2; ~i; --i) {
            minm = min(minm, a[i+1]);
            if(v[i] + minm >= k) res++;
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,K;
        cin>>N>>K;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        cout<<ob.totalCuts(N,K,A)<<endl;
    }
    return 0;
}
// } Driver Code Ends