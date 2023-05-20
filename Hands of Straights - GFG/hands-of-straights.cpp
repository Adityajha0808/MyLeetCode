//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int n, int sz, vector<int>& a) {
        map<int,int> mp;
        for(auto& i: a) mp[i]++;
        for(auto& i: mp)
            if(mp[i.first] > 0)
                for(int j=sz-1; ~j; --j)
                    if((mp[i.first + j] -= mp[i.first]) < 0)
                        return false;
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends