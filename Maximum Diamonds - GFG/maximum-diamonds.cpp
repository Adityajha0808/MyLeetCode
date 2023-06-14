//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    using ll = long long;
    
    ll maxDiamonds(int a[], int n, int k) {
        ll res = 0;
        priority_queue<int> pq;
        for(int i=0; i<n; ++i) pq.push(a[i]);
        while(k--) {
            res += pq.top();
            int x = pq.top();
            pq.pop();
            pq.push(x/2);
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        
        cin>>N>>K;
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.maxDiamonds(A,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends