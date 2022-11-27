//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	string addBinary(string a, string b) {
	    int n1 = a.size(), n2 = b.size();
	    int diff = abs(n1 - n2);
	    string str = "";
	    while(diff--) str.push_back('0');
	    if(n1 > n2) {
	        str += b;
	        b = str;
	        n2 = n1;
	    } else if(n2 > n1) {
	        str += a;
	        a = str;
	        n1 = n2;
	    }
	    string res = "";
	    int carry = 0;
	    for(int i=n1-1; ~i; --i) {
	        if(carry) {
	            if(a[i] == '1' and b[i] == '1') {
	                res.push_back('1');
	                carry = 1;
	            } else if(a[i] == '1' or b[i] == '1') {
	                res.push_back('0');
	                carry = 1;
	            } else {
	                res.push_back('1');
	                carry = 0;
	            }
	        } else {
	            if(a[i] == '1' and b[i] == '1') {
	                res.push_back('0');
	                carry = 1;
	            } else if(a[i] == '1' or b[i] == '1') {
	                res.push_back('1');
	                carry = 0;
	            } else {
	                res.push_back('0');
	                carry = 0;
	            }
	        }
	    }
	    if(carry) res.push_back('1');
	    while(res.size() and res.back() == '0') res.pop_back();
	    reverse(res.begin(), res.end());
	    return res;
	}
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		string A, B; cin >> A >> B;
		Solution ob;
		cout << ob.addBinary (A, B);
		cout << "\n";
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends