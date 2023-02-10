//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s) {
        int res = 0, b = 0, a = 0, l = 0, o = 0, n = 0;
        for(auto& i: s) {
            if(i == 'b') b++;
            else if(i == 'a') a++;
            else if(i == 'l') l++;
            else if(i == 'o') o++;
            else if(i == 'n') n++;
            if(b and a and l > 1 and o > 1 and n) {
                res++;
                b--; a--; l -= 2; o -= 2; n--;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends