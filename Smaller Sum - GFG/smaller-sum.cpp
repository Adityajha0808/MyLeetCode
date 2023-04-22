//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    using ll = long long;
    vector<ll> smallerSum(int n, vector<int>& a) {
        vector<ll> res, v, sum;
        v.assign(a.begin(), a.end());
        sort(v.begin(), v.end());
        sum.push_back(v[0]);
        for(int i=1; i<n; ++i) sum.push_back(v[i] + sum[i-1]);
        for(int i=0; i<n; ++i) {
            int idx = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
            res.push_back(idx == 0 ? 0 : sum[idx - 1]);
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
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends