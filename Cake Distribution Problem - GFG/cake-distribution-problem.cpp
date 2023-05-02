//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    bool canSplit(vector<int>& sweetness, int mn_value, int k) {
    int curr = 0;
    int cnt = 0;
    
    for (int i = 0; i < sweetness.size(); i++) {
        curr += sweetness[i];
        if (curr >= mn_value) {
            cnt++;
            curr = 0;
        }
    }
    return cnt >= k + 1;
}


int maxSweetness(vector<int>& sweetness, int n, int k) {
    int sum = 0;
    int mn_value = INT_MAX;
    for (int i = 0; i < n; i++) {
        sum += sweetness[i];
        mn_value = min(mn_value, sweetness[i]);
    }
    
    int low = 1;
    int high = sum;
    int ans = 0;
    
    while (low <= high) {
        int mid = (low + high) / 2;
        if (canSplit(sweetness, mid, k)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> sweetness(n);
        for (int i = 0; i < n; i++) {
            cin >> sweetness[i];
        }
          Solution ob;
          int res=ob.maxSweetness(sweetness, n, k);
        cout << res << endl;
    }
}
// } Driver Code Ends