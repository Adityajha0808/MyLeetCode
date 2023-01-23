//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string removePair(string s) {
        string str = "";
        str.push_back(s[0]);
        int i = 1;
        while(i < s.size()) {
            while(str.size() and str.back() == s[i]) {
                str.pop_back();
                i++;
            }
            if(i < s.size()) str.push_back(s[i++]);
        }
        return (str.size() ? str : "-1");
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s; 
        cin>>s;
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends