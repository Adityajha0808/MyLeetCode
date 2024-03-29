//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int carpetBox(int A, int B, int C, int D) {
        int a = A, b = B, c = C, d = D, res1 = 0, res2 = 0;
        while(a > c) {
            a /= 2;
            res1++;
        }
        while(b > d) {
            b /= 2;
            res1++;
        }
        a = A, b = B, c = C, d = D;
        while(b > c) {
            b /= 2;
            res2++;
        }
        while(a > d) {
            a /= 2;
            res2++;
        }
        return min(res1, res2);
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int A,B,C,D;
        cin>>A>>B>>C>>D;
        
        Solution ob;

        int ans = ob.carpetBox(A,B,C,D);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends