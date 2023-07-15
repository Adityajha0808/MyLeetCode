//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    void deleteMid(stack<int>& s, int n) {
        stack<int> st;
        int i = n;
        while(s.size()) {
            if(n%2 and --i == n/2) {
                s.pop();
                continue;
            } else if(n%2 == 0 and i-- == n/2) {
                s.pop();
                continue;
            }
            st.push(s.top());
            s.pop();
        }
        while(st.size()) {
            s.push(st.top());
            st.pop();
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends