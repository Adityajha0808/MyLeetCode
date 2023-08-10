//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution {
public:
    int lcs(int l1, int l2, string s1, string s2) {
        vector<int> dp(l2+1,0);
        for(int i=0; i<l1; ++i) {
            int prev = 0;
            for(int j=0; j<l2; ++j) {
                int next = dp[j+1];
                dp[j+1] = (s1[i] == s2[j] ? prev + 1 : max(dp[j], next));
                prev = next;
            }
        }
        return dp.back();
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends