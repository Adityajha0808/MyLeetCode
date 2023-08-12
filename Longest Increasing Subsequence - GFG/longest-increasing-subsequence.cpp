//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[]) {
        vector<int> nums;
        for(int i=0; i<n; ++i) nums.push_back(a[i]);
        vector<int>::iterator m = nums.begin();  // m will mark the virtual "S.end()".
    for (int& val : nums) {
        auto it = lower_bound(nums.begin(), m, val);
        *it = val;
        if (it == m)
            m++;
    }
    
    return m - nums.begin();
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends