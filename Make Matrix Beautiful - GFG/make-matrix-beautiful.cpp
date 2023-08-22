//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    int findMinOpeartion(vector<vector<int>> matrix, int n) {
        int sumRow[n];
    int sumCol[n];
    for(int i=0; i<n; i++)
        sumRow[i] = sumCol[i] = 0;
    
    //calculating sumRow[] and sumCol[] array.
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            sumRow[i] += matrix[i][j];
            sumCol[j] += matrix[i][j];
        }
    }
            
    //finding maximum sum value in either row or in column.
    int maxSum = 0;
    for (int i = 0; i < n; ++i)
    {
        maxSum = max(maxSum, sumRow[i]);
        maxSum = max(maxSum, sumCol[i]);
    }
    
    int count = 0;
    for (int i = 0, j = 0; i < n && j < n;) 
    {
        //finding minimum increment required in either row or column.
        int diff = min(maxSum - sumRow[i],  maxSum - sumCol[j]);
        
        //adding difference in corresponding cell, sumRow[] and sumCol[] array.
        matrix[i][j] += diff;
        sumRow[i] += diff;
        sumCol[j] += diff;
        
        //updating the result.
        count += diff;
        
        //if ith row is satisfied, incrementing i for next iteration.
        if (sumRow[i] == maxSum)
            ++i;
        
        //if jth column is satisfied, incrementing j for next iteration.
        if (sumCol[j] == maxSum)
            ++j;
    }
    //returning the result.
    return count;
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
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends