//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int n, vector<int>& a) {
        vector<int> res;
        res.push_back(a[0]);
        for(int i=1; i<n; ++i) {
            bool go = true;
            if(res.size()) {
                if(res.back() > 0 and a[i] < 0) {
                    go = false;
                    if(res.back() == abs(a[i])) res.pop_back();
                    else if(res.back() < abs(a[i])) {
                        res.pop_back();
                        res.push_back(a[i]);
                    }
                }
                while(res.size() > 1 and res.back() < 0) {
                    int curr = res.back();
                    res.pop_back();
                    if(res.back() < 0) {
                        res.push_back(curr);
                        break;
                    }
                    go = false;
                    if(res.size() and res.back() > abs(curr)) continue;
                    else if(res.size() and res.back() < abs(curr)) {
                        res.pop_back();
                        res.push_back(curr);
                    } else if(res.size() and res.back() == abs(curr)) {
                        res.pop_back();
                    }
                }
            }
            if(go) res.push_back(a[i]);
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends