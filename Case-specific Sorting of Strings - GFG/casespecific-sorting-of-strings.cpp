//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    string caseSort(string s, int n) {
        string u, l;
        for(int i=0; i<n; ++i) {
            if(isupper(s[i]))
                u.push_back(s[i]);
            else
                l.push_back(s[i]);
        }
        sort(u.begin(), u.end());
        sort(l.begin(), l.end());
        int x = 0, y = 0;
        for(int i=0; i<n; ++i) {
            s[i] = (isupper(s[i]) ? u[x++] : l[y++]);
        }
        return s;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends