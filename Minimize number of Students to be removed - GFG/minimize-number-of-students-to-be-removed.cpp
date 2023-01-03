//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int removeStudents(int a[], int n) {
        vector<int> res;
        for(int i=0; i<n; ++i) {
            auto it = lower_bound(res.begin(), res.end(), a[i]);
            if(it == res.end())
                res.push_back(a[i]);
            else
                *it = a[i];
        }
        return n - res.size();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int H[N];
        for(int i=0; i<N; i++)
            cin>>H[i];

        Solution ob;
        cout << ob.removeStudents(H,N) << endl;
    }
    return 0;
}
// } Driver Code Ends