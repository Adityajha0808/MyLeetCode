//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    bool checkUtil(int num, int dig, int base) 
{ 
    // Base case 
    if (dig==1 && num < base) 
       return true; 
  
    // If there are more than 1 digits left and number 
    // is more than base, then remove last digit by doing 
    // num/base, reduce the number of digits and recur 
    if (dig > 1 && num >= base) 
       return checkUtil(num/base, --dig, base); 
  
    return false; 
} 
  
// return true of num can be represented in 'dig' 
// digits in any base from 2 to 32 
bool check(int num, int dig) 
{ 
    // Check for all bases one by one 
    for (int base=2; base<=32; base++) 
       if (checkUtil(num, dig, base)) 
            return true; 
    return false; 
}
string baseEquiv(int n, int m){
    if(check(n, m)) return "Yes";
    else return "No"; 
}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        Solution ob;
        cout<<ob.baseEquiv(n,m)<<endl;
    }
    return 0;
}

// } Driver Code Ends