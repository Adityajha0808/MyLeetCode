//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
      string maxSum(string w,char x[], int b[],int n){
          map<int,int> hash;
        for(int i=0;i<n;i++)
        {
            hash[(int)x[i]]=i+1;
        }
        
        // intialize the maximum sum so far as zero
        int max_so_far=0,max_ending_here=0;
        
        int start=0,end=0,s=0;
        
        char k=w[0];
        
        // update the max sum so far as first charcter ascii value
        if(hash[k]==0)
            max_so_far=(int)k;
        else
            max_so_far=b[hash[k]-1];
        
        // Kadane's Algorithm
        for(int i=0;i<w.length();i++)
        {
            char d=w[i];
            if(hash[d]==0)
            {
                max_ending_here+=(int)d;
            }
            else
            {
                max_ending_here+=b[hash[d]-1];
            }
            
            if (max_so_far < max_ending_here)
            {
                max_so_far = max_ending_here;
                start = s;
                end = i;
            }
     
            if (max_ending_here < 0)
            {
                max_ending_here = 0;
                s = i+1;
            }
        }
        
        // Find the substring from start to end
        string ans = "";
        for(int i = start;i<=end;i++)
        {
            ans += w[i];
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
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}
// } Driver Code Ends