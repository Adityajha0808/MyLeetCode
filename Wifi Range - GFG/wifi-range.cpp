//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    bool wifiRange(int n, string s, int k) {
        int leftwifi = -1, rightwifi;
        vector<int> right;
        for(int i=n-1; ~i; --i)
            if(s[i] == '1')
                right.push_back(i);
        reverse(right.begin(), right.end());
        for(int i=0; i<n; ++i) {
            if(s[i] == '1')
                leftwifi = i;
            else {
                rightwifi = right[upper_bound(right.begin(), right.end(), i) - right.begin()];
                int leftCondition = (leftwifi == -1 ? INT_MAX : i - leftwifi);
                int rightCondition = (i > right.back() ? INT_MAX : rightwifi - i);
                int minm = min(leftCondition, rightCondition);
                if(minm > k) return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, X;
        string S;
        cin >> N >> X >> S;
        Solution obj;
        cout << obj.wifiRange(N, S, X) << "\n";
    }
}

// } Driver Code Ends