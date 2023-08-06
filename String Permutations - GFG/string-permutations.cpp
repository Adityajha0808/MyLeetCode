//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<string> res;
    void func(string& s, int l, int r) {
        if(l == r)
            res.push_back(s);
        else {
            for(int i=l; i<=r; ++i) {
                swap(s[l], s[i]);
                func(s, l+1, r);
                swap(s[l], s[i]);
            }
        }
    }
    
    vector<string> permutation(string s) {
        func(s, 0, s.size()-1);
        sort(res.begin(), res.end());
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends