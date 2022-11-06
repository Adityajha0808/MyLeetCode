//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int N)
    {
        int dp[N+1], dp2[N+1];
        int a[10] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
        dp[0] = 0;
        dp2[0] = 0;
        for(int i = 1;i <= N;i++){
            dp[i] = INT_MAX;
            dp2[i] = -1;
        }
        
        for(int j = 0;j < 10;j++){
            for(int i = 0;i <= N;i++){
                if(i >= a[j]){
                    dp[i] = min(dp[i], 1+ dp[i-a[j]]);
                    dp2[i] = j;
                }
            }
        }
        
        int k = N;
        vector<int> v;
        for(int i = N;i > 0 && N >= 0;){
            if(dp2[i] != -1)
                v.push_back(a[dp2[i]]);
            N = N - a[dp2[i]];
            i = N;
        }
        
        return v;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends