//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> reverseSpiral(int R, int C, vector<vector<int>>&a)  {
        // code here
        vector<int>ans;
    // Large array to initialize it 
    // with elements of matrix 
    long int b[R*C+1]; 
      
    /* k - starting row index 
    l - starting column index*/
    int i, k = 0, l = 0; 
      
    // Counter for single dimension array 
    //in which elements will be stored 
    int z = 0; 
      
    // Total elements in matrix 
    int size = R*C; 
  
    while (k < R && l < C) 
    { 
        // Variable to store value of matrix. 
        int val; 
          
        /* Print the first row from the remaining rows */
        for (i = l; i < C; ++i) 
        { 
            // printf("%d ", a[k][i]); 
            val = a[k][i]; 
            b[z] = val; 
            ++z; 
        } 
        k++; 
  
        /* Print the last column from the remaining columns */
        for (i = k; i < R; ++i) 
        { 
            // printf("%d ", a[i][n-1]); 
            val = a[i][C-1]; 
            b[z] = val; 
            ++z; 
        } 
        C--; 
  
        /* Print the last row from the remaining rows */
        if ( k < R) 
        { 
            for (i = C-1; i >= l; --i) 
            { 
                // printf("%d ", a[m-1][i]); 
                val = a[R-1][i]; 
                b[z] = val; 
                ++z; 
            } 
            R--; 
        } 
  
        /* Print the first column from the remaining columns */
        if (l < C) 
        { 
            for (i = R-1; i >= k; --i) 
            { 
                // printf("%d ", a[i][l]); 
                val = a[i][l]; 
                b[z] = val; 
                ++z; 
            } 
            l++; 
        } 
    } 
    for (int i=size-1 ; i>=0 ; --i) 
    { 
        ans.push_back(b[i]); 
    }
    return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin>>R>>C;
        vector<vector<int>> a(R, vector<int>(C, 0));
        for(int i = 0;i < R*C;i++)
            cin>>a[i/C][i%C];
        Solution ob;
        vector<int>ans=ob.reverseSpiral(R,C,a);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
            cout<<endl;
    }
    return 0;
}

// } Driver Code Ends