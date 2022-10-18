//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	public:
	vector<int> downwardDigonal(int n, vector<vector<int>> a) {
	    vector<int> res;
		for(int k=0; k<n; ++k) {
            int row = 0, col = k;
            while(col >= 0) {
                res.push_back(a[row][col]);
                row++, col--;
            }
        }
        for(int j=1; j<n; ++j) {
            int col = n-1, row = j;
            while(row < n) {
                res.push_back(a[row][col]);
                row++, col--;
            }
        }
        return res;
	}

};

//{ Driver Code Starts.



int main()
{

    
    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;

        vector<vector<int>> A(n, vector<int>(n));

        for(int i = 0; i < n; i++)
        	for(int j = 0; j < n; j++)
        		cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDigonal(n, A);

        for(auto i:ans)
        	cout << i << " ";

	    cout << "\n";
    }

    return 0;
}

// } Driver Code Ends