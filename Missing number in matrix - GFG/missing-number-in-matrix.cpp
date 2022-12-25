//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    using ll = long long;
    ll MissingNo(vector<vector<int>>& a) {
        int n = a.size();
        unordered_map<ll,int> mpRow, mpCol;
        ll minmRow = LLONG_MAX, maxmRow = -1, minmCol = LLONG_MAX, maxmCol = -1, diagSum1 = 0, diagSum2 = 0;
        bool inDiag1 = false, inDiag2 = false;
        for(int i=0; i<n; ++i) {
            ll rowSum = 0, colSum = 0;
            for(int j=0; j<n; ++j) {
                if(i == j) {
                    if(a[i][j] == 0)
                        inDiag1 = true;
                    diagSum1 += a[i][j];
                }
                if(i + j == n - 1) {
                    if(a[i][j] == 0)
                        inDiag2 = true;
                    diagSum2 += a[i][j];
                }
                rowSum += a[i][j];
                colSum += a[j][i];
            }
            mpRow[rowSum]++;
            mpCol[colSum]++;
            minmRow = min(minmRow, rowSum);
            maxmRow = max(maxmRow, rowSum);
            minmCol = min(minmCol, colSum);
            maxmCol = max(maxmCol, colSum);
        }
        if(mpRow.size() > 2 or mpCol.size() > 2) return -1;
        if(!inDiag1 and (diagSum1 != maxmRow or diagSum1 != maxmCol)) return -1;
        if(!inDiag2 and (diagSum2 != maxmRow or diagSum2 != maxmCol)) return -1;
        if(inDiag1 and diagSum1 != minmRow) return -1;
        if(inDiag2 and diagSum2 != minmRow) return -1;
        if(maxmRow == minmRow or maxmCol == minmCol) return -1;
        if(maxmRow - minmRow != maxmCol - minmCol) return -1;
        return maxmRow - minmRow;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>> matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		long long int ans = ob.MissingNo(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends