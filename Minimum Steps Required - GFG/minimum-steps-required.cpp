//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string s) {
    int n = s.size(), a = 0, b = 0;
    for(int i=1; i<n; ++i) {
        if(s[i] == 'a' and s[i-1] == 'a') continue;
        if(s[i-1] == 'a' and s[i] == 'b') a++;
        if(s[i] == 'b' and s[i-1] == 'b') continue;
        if(s[i-1] == 'b' and s[i] == 'a') b++;
    }
    s.back() == 'a' ? a++ : b++;
    return min(a + 1, b + 1);
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends