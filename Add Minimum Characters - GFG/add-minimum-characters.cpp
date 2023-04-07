//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int addMinChar(string s1) {    
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        string s = s1 + '$' + s2;
        int n = s.size(), i = 1, l = 0;
		vector<int> a(n, 0);
		a[0] = 0;
    	while(i < n) {
        	if(s[i] == s[l])
            	a[i++] = ++l;
        	else {
            	if(l)
            	    l = a[l - 1];
            	else
                	a[i++] = 0;
    		}
    	}
    	return s1.size() - a[n - 1];
    }
};

//{ Driver Code Starts.


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin >> str;
        
        Solution ob;
        cout << ob.addMinChar(str) << endl;
    }
    return 0; 
} 
// } Driver Code Ends