//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int numberOfSubsequences(string S, string W){
        int ans=0;

        while(1){  // Untill no such subsequence exist
    
            int i=0,j=0,flag=0;
    
            while(i<S.size()){
    
    
                if(S[i]==W[j]){
    
                    ++j;
                    S[i]='*';
    
                    if(j==W.size()){ 
    
                        ++ans;
                        flag=1;  //  A subsequence found
                        break;
    
                    }
                }

                ++i;
            }
    
            if(flag==0)  // No subsequence found in this iteration
                break;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S,W;
        cin >> S >> W;
        Solution ob;
        cout << ob.numberOfSubsequences(S,W) << endl;
    }
    return 0; 
} 


// } Driver Code Ends