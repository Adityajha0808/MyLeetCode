class Solution {
public:
    int maximumRows(vector<vector<int>>& a, int cols) {
        int n = a.size(), m = a[0].size(), possible = pow(2, m) - 1;
        vector<vector<int>> v(possible + 1, vector<int> (m,0));
        for(int i=0; i<=possible; ++i) {
            int el = i;
            for(int j=0; j<m; ++j)
                if((i & (1<<j)) >= 1)
                    v[i][j] = 1;
        }
        int maxm = 0;
        for(int i=0; i<=possible; ++i) {
            int cnt=0, gnt = 0;
            set<int> st;
            for(int j=0; j<m; ++j) {
                if(v[i][j] == 1) {
                    st.insert(j);
                    cnt++;
                }
            }
            if(cnt == cols) {
                for(int i=0; i<n; ++i) {
                    bool ok = 0;
                    for(int j=0; j<m; ++j) {
                        if(st.count(j)==0)
                            if(a[i][j] == 1) ok = 1;
                    }
                    if(ok == 0) gnt++;
                }
            } 
            maxm = max(maxm, gnt);
        }
        return maxm;
    }
};