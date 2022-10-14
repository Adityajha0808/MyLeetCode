//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 
  

// } Driver Code Ends

class Solution{
  public:
  int maximizeSum(int a[], int n){
      
        unordered_map<int, int> ans;
        int sum=0;
        bool arr[n];
        for(int i=0;i<n;i++){
            arr[i]=false;
        }
        for (int i = 0; i < n; i++)
        	ans[a[i]]++;
        
        for(int i=n-1;i>=0;i--)
        {
            if(arr[i] == false)
            {
                arr[i]=true;
                sum+= a[i];
                if(ans[a[i]-1] > 0)
                {
                    arr[i-ans[a[i]]]=true;
                    ans[a[i]-1]--;
                }
            }
        }
        return sum;
    }
  
};

//{ Driver Code Starts.



int main()
{
    
    int t;cin>> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr, arr+n);
        Solution ob;
        
        cout << ob.maximizeSum(arr, n) << endl;
        
        
    }

}


// } Driver Code Ends