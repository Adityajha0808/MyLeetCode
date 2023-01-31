//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    
    bool isSubstring(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size(), j;
        for(int i=0; i<=n2-n1; ++i) {
            for(j=0; j<n1; ++j)
                if(s2[i+j] != s1[j]) break;
            if(j == n1) return true;
        }
        return false;
    }
    
    int minRepeats(string a, string b) {
        string s = a;
        int res = 1;
        while(s.size() < b.size()) {
            s += a;
            res++;
        }
        if(isSubstring(b, s)) return res;
        return (isSubstring(b, s+a) ? res + 1 : -1);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ",&t);
    while (t--) {
        string A,B;
        getline(cin,A);
        getline(cin,B);

        Solution ob;
        cout << ob.minRepeats(A,B) << endl;
    }
    return 0;
}
// } Driver Code Ends