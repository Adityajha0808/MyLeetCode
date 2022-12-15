//{ Driver Code Starts
// Initial template for c++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for c++

class Solution {
  public:
    int sumofdig(int n) {
        string s = to_string(n);
        int sum = 0;
        for(auto i: s)
            sum += (i - '0');
        return sum;
    }
    string BalancedString(int n) {
        string s = "";
        bool check = false;
        if(n%2) {
            int sum = sumofdig(n);
            if(sum%2) check = true;
        }
        if(n > 26) {
            string x = "";
            for(auto i='a'; i<='z'; ++i) x.push_back(i);
            int r = n/26;
            n -= (r*26);
            while(r--) s += x;
        }
        int ch = 97;
        for(int i=1; i<=n/2; ++i)
            s.push_back((char)ch++);
        if(n%2 and !check)
            s.push_back((char)ch);
        string x = "";
        ch = 122;
        for(int i=1; i<=n/2; ++i)
            x.push_back((char)ch--);
        if(n%2 and check)
            x.push_back((char)ch);
        reverse(x.begin(), x.end());
        s += x;
        return s;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.BalancedString(N) << endl;
    }
    return 0;
}

// } Driver Code Ends