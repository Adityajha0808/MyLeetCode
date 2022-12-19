//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<pair<int, int>> adj[501];

    void dijkstra(vector<int>& costToReach, int source, int n) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;
        pq.push({0, source});

        // Time for starting node is 0
        costToReach[source] = 0;

        while (!pq.empty()) {
            int currNodeCost = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();

            if (currNodeCost > costToReach[currNode]) {
                continue;
            }

            // Broadcast the signal to adjacent nodes
            for (pair<int, int> edge : adj[currNode]) {
                int cost = edge.first;
                int neighborNode = edge.second;

                // Fastest signal cost for neighborNode so far
                // costToReach[currNode] + cost :
                // cost when signal reaches neighborNode
                if (costToReach[neighborNode] > currNodeCost + cost) {
                    costToReach[neighborNode] = currNodeCost + cost;
                    pq.push({costToReach[neighborNode], neighborNode});
                }
            }
        }
    }
    int minimumCost(vector<vector<int>>& flights, int n, int k) {
        for (vector<int> f : flights) {
            int source = f[0];
            int dest = f[1];
            int travelCost = f[2];

            adj[source].push_back({travelCost, dest});
        }

        vector<int> costToReach(n + 1, INT_MAX);
        dijkstra(costToReach, k, n);

        int answer = INT_MIN;
        for (int i = 1; i <= n; i++) {
            answer = max(answer, costToReach[i]);
        }

        // INT_MAX signifies atleat one node is unreachable
        return answer == INT_MAX ? -1 : answer;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int size;
        cin >> size;
        vector<vector<int>> flights(size,vector<int>(3));
        for (int i = 0; i < size; i++) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            flights[i]=temp;
        }

        Solution ob;
        cout << ob.minimumCost(flights, n, k) << "\n";
    }
}

// } Driver Code Ends