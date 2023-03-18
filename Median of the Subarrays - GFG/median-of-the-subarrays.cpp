//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
    public:
  
    using ll = long long;
    
    ll func(int& n, vector<int>& a, int m) {
        vector<int> v(2*n + 1, 0);
        ll curr = n, sum = 0, res = 0;
        v[curr]++;
        for(int i=0; i<n; ++i) {
            int tmp = -1;
            if(a[i] >= m) tmp=1;
            if(tmp == -1) sum -= v[curr + tmp];
            else sum+=v[curr];
            curr += tmp;
            res += sum;
            v[curr]++;
        }
        return res;
    }
 
    ll countSubarray(int n, vector<int> a, int m) {
        return func(n, a, m) - func(n, a, m+1);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin>>N>>M;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution obj;
        auto ans = obj.countSubarray(N,A,M);
        cout<<ans<<endl;
    }
}  
// } Driver Code Ends