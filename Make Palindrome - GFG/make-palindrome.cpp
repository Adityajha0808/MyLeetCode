//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    bool makePalindrome(int n, vector<string>& a) {
        unordered_map<string, int> mp;
        for(int i=0; i<n; ++i) {
            if(mp.find(a[i]) != mp.end() and mp.find(a[i])->second) {
                mp[a[i]]--;
                if(mp[a[i]] == 0) mp.erase(mp.find(a[i]));              
            } else {
                string s = a[i];
                reverse(s.begin(), s.end());
                mp[s]++;
            }
        }
        if(mp.size() == 1) {
            string s = mp.begin()->first;
            reverse(s.begin(), s.end());
            if(mp.begin()->first == s) return true;
        } 
        return mp.empty() ? true : false;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        if(ob.makePalindrome(n,arr)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
// } Driver Code Ends