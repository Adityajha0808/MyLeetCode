//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool is_possible_to_get_seats(int k, int n, vector<int>& a) {
        if(k == 0 or (n == 1 and k <= 1 and a[0] == 0)) return true;
        if(a[0] == 0 and a[1] == 0) {
            k--;
            if(k <= 0) return true;
            a[0] = 1;
        }
        for(int i=1; i<n-1; ++i) {
            if(k <= 0) return true;
            if(a[i] == 0 and a[i-1] == 0 and a[i+1] == 0) {
                k--;
                a[i] = 1;
            }
        }
        return (k == 0 or (a[n-1] == 0 and a[n-2] == 0 and k <= 1)) ? true : false;
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int m;
        cin >> m;
        vector<int> seats(m);
        for (int i = 0; i < m; i++) {
            cin >> seats[i];
        }
        Solution obj;
        if (obj.is_possible_to_get_seats(n, m, seats)) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
}

// } Driver Code Ends