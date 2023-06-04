//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    string reverseEqn(string s) {
        int n = s.size();
        stack<string> num;
        stack<char> ops;
        for(int i=0; i<n; ++i) {
            if(s[i] < '0' or s[i] > '9') {
                ops.push(s[i]);
            } else {
                int j = i;
                string x = "";
                while(j<n and s[j] >= '0' and s[j] <= '9')
                    x.push_back(s[j++]);
                num.push(x);
                i = j-1;
            }
        }
        s.clear();
        while(num.size()) {
            s += num.top();
            num.pop();
            if(num.empty()) break;
            s += ops.top();
            ops.pop();
        }
        return s;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends