//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class IntArray
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
public:
    using ll = long long;  
    ll findMaxSubsetSum(int n, vector<int>& a) {
        vector<vector<ll>> dp(n+2, vector<ll> (2, 0));
        for(int i=1; i<=n; ++i) {
            dp[i][0] = dp[i-1][1];
            dp[i][1] = max(dp[i-1][1] + a[i-1], dp[i-1][0] + a[i-1]);
        }
        return max(dp[n][0], dp[n][1]);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        IntArray::input(A,N);
        
        Solution obj;
        long long res = obj.findMaxSubsetSum(N, A);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends