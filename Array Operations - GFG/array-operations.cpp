//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int arrayOperations(int n, vector<int>& arr) {
        int count=0,zero=0;
        bool isNonZero=0,isZeroFound=0;
        
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                zero++;
                isZeroFound=1;
                if(isNonZero){
                    count++;
                    isNonZero=0;
                }
            }else{
                isNonZero=1;
                
            }
        }
        if(isNonZero && isZeroFound){
            count++;
        }
        
        if(zero==n) return 0;
        
        return count>0?count:-1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution obj;
        int res = obj.arrayOperations(n, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends