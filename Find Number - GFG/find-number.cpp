//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    using ll = long long;
    ll findNumber(ll n) {
        vector<int> a = { 9, 1, 3, 5, 7 };
        ll res = 0;
        while(n) {
            res = res * 10 + a[n%5];
            if(n%5 == 0) {
                n /= 5;
                n--;
            } else
                n /= 5;
        }
        queue<int> q;
        while(res) {
            q.push(res%10);
            res /= 10;
        }
        while(q.size()) {
            res = res * 10 + q.front();
            q.pop();
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long N;
        cin>>N;
        Solution ob;
        cout<<ob.findNumber(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends