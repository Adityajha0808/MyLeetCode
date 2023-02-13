//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for c++

class Solution{
public:
    int inSequence(int a, int b, int c) {
        int diff = (b - a);
        if(diff == 0) return 1;
        if(diff < 0) {
            if(c >= 0) return 0;
            if(diff%c == 0) return 1;
        } else {
            if(c <= 0) return 0;
            if(diff%c == 0) return 1;
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int A, B, C;
        cin>>A>>B>>C;
        
        Solution ob;
        cout<<ob.inSequence(A, B, C)<<endl;
    }
    return 0;
}
// } Driver Code Ends