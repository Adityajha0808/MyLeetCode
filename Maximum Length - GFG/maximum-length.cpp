//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int solve(int a, int b, int c) {
        char prev = '0';
        vector<int> v = {a, b, c};
        string res;
        while(true) {
            int maxm = 0;
            char curr;
            for(int i=0; i<3; ++i)
                if(prev != char(i + 'a') and maxm < v[i])
                    maxm = v[i], curr = i + 'a';
            if(maxm == 0) break;
            res += curr;
            v[curr - 'a']--;
            if(maxm >= 2 and (prev == '0' or maxm > v[prev - 'a'])) {
                res += curr;
                v[curr - 'a']--;
            }
            prev = curr;
        }
        if(res.size() != a + b + c) return -1;
        return a + b + c;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;

        Solution ob;
        int ans = ob.solve(a, b, c);
     

        cout <<  ans << "\n";
    }
    return 0;
}
// } Driver Code Ends