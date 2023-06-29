//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int isHappy(int n) {
        if(n == 1 or n == 7) return 1; 
        int sum = n, x = n; 
        while(sum > 9) { 
            sum = 0; 
            while (x) {
                int d = x%10;
                sum += d*d;
                x /= 10;
            }
            if(sum == 1) return 1;
            x = sum;
        }
        return (sum == 7 ? 1 : 0);
    }
    
    int nextHappy(int n) {   
        int x = n+1, res = x;
        while(true) {
            if(isHappy(x)) return x;
            res = ++x;
        }
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends