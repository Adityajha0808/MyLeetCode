//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {

  public:
    int noConseBits(int n) {
        int res = 0;
        vector<bool> a(35, false);
        for(int i=30; ~i; --i)
            if((1 << i) & n)
                a[i] = true;
        for(int i=30; i>=2; --i) {
            if(a[i]) {
                res |= (1 << i);
                if(a[i-1])
                    a[i-2] = false;
            }
        }
        if(a[1]) res |= 2;
        if(a[0]) res |= 1;
        return res;
    }
};


//{ Driver Code Starts.

int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        int ans = sol.noConseBits(n);
        cout << ans << '\n';
    }

    return 0;
}

// } Driver Code Ends