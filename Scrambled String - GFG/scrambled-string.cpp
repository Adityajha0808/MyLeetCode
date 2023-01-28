//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

//Back-end complete function Template for C++

class Solution{
    public:
    unordered_map<string, int> mp;
    bool isScramble(string s1, string s2) {
        if(s1 == s2) return true;
        if(s1.size() != s2.size()) return false;
        if(mp.find(s1 + " " + s2) != mp.end()) return mp[s1 + " " + s2];
        int n = s1.size();
        for(int i=1; i<n; ++i) {
            if(isScramble(s1.substr(0, i), s2.substr(0,i)) and isScramble(s1.substr(i, n-i), s2.substr(i, n-i)))
                return mp[s1+" "+s2] = true;
            else if(isScramble(s1.substr(0, i), s2.substr(n-i, i)) and isScramble(s1.substr(i, n-i),s2.substr(0, n-i)))
                return mp[s1 + " " + s2] = true;
        }
        return mp[s1 + " " + s2] = false;
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1>>S2;
        Solution ob;
        
        if (ob.isScramble(S1, S2)) {
            cout << "Yes";
        }
        else {
            cout << "No";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends