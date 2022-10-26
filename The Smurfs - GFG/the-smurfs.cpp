//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int findMin(int n, char a[]){
        // code here
        int cntr = 0, cntg = 0, cntb = 0;
        for(int i = 0;i < n;i++){
            if(a[i] == 'R')
                cntr++;
            else if(a[i] == 'G')
                cntg++;
            else
                cntb++;
        }
        if(cntr == n || cntg == n || cntb == n)
            return n;
        else if(cntr&1 && cntg&1 && cntb&1)
            return 2;
        else if(cntr%2 == 0 && cntg%2 == 0 && cntb%2 == 0)
            return 2;
        return 1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        char a[n];
        for(int i = 0;i < n;i++)
            cin>>a[i];
        
        Solution ob;
        cout<<ob.findMin(n, a)<<"\n";
    }
    return 0;
}
// } Driver Code Ends