//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    
    using ll = long long;
    
    void merge(vector<ll>& a, ll l, ll m, ll r, ll& inv) {
        vector<ll> tmp(r-l+1, 0);
        ll i = l, j = m+1, k = 0, cnt = 0;
        while(i<=m and j<=r) {
            if(a[i] <= a[j])
                tmp[k++] = a[i++];
            else {
                inv += (m-i+1);
                tmp[k++] = a[j++];
            }
        }
        while(i<=m)
            tmp[k++] = a[i++];
        while(j<=r)
            tmp[k++] = a[j++];
        k = 0;
        for(ll i=l; i<=r; ++i)
            a[i] = tmp[k++];
    }
 
    void mergeSort(vector<ll>& a, ll l, ll r, ll& inv) {
        if(l < r) {
            ll m = (l + r)/2;
            mergeSort(a, l, m, inv);
            mergeSort(a, m+1, r, inv);
            merge(a, l, m, r, inv);
        }
    }

    ll CountInversions(vector<ll>& a) {
        ll n = a.size(), inv = 0;
        mergeSort(a, 0, n-1, inv);
        return inv;
    }

    ll countSubstring(string s) {
        ll n = s.size(), cnt = 0;
        vector<ll> a(n, 0), pre(n, 0);
        for(ll i=0; i<n; ++i) {
            a[i] = s[i] - '0';
            if(a[i] == 0)
                a[i] = -1;
        }
        pre[0] = a[0];
        for(ll i=1; i<n; ++i)
            pre[i] = a[i] + pre[i-1];
        for(ll i=0; i<n; ++i)
            if(pre[i] > 0)
                cnt++;
        reverse(pre.begin(), pre.end());
        return cnt + CountInversions(pre);
    }
};

//{ Driver Code Starts.
int main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
 int t=1;
 cin>>t;
 for(int i=1;i<=t;i++){
    string S;
    cin>>S;
    Solution obj;
    long long ans =obj.countSubstring(S);
    cout<<ans<<endl;
 }
}
// } Driver Code Ends