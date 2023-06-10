//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define ll long long

// } Driver Code Ends
class Solution
{
    public:
        void Rearrange(int a[], int n) {
            vector<int> pos, neg;
            for(int i=0; i<n; ++i) {
                if(a[i] < 0)
                    neg.push_back(a[i]);
                else
                    pos.push_back(a[i]);
            }
            int l = 0, r = 0;
            for(int i=0; i<n; ++i) {
                if(l < neg.size())
                    a[i] = neg[l++];
                else
                    a[i] = pos[r++];
            }
        }
};

//{ Driver Code Starts.
void Rearrange(int arr[], int n);

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        long long j=0;
        Solution ob;
        ob.Rearrange(arr, n);
      
        for (int i = 0; i < n; i++) 
            cout << arr[i] << " "; 
        cout << endl;  
    }
    return 0; 
} 
// } Driver Code Ends