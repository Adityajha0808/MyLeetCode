//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User Function Template for C++ solution

class Solution {
  public:
    using ll = long long;
    vector<ll> nextLargerElement(vector<ll>& a, int n) {
        vector<ll> res;
        stack<ll> st;
        res.push_back(-1);
        st.push(a[n-1]);
        for(int i=n-2; ~i; --i) {
            if(st.top() > a[i])
                res.push_back(st.top());
            else {
                while(st.size() and st.top() <= a[i])
                    st.pop();
                if(st.size())
                    res.push_back(st.top());
                else
                    res.push_back(-1);
            }
            st.push(a[i]);
        }
        reverse(res.begin(), res.end());
        return res;
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
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution ob;
        
        vector <long long> res = ob.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}

// } Driver Code Ends