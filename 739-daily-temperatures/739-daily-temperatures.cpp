class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& a) {
        int n = a.size();
        vector<int> st;
        vector<int> v(n, 0);
        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && a[st.back()] <= a[i]) {
                st.pop_back();
            }
            v[i] = (st.empty() ? 0 : st.back()-i);
            st.push_back(i);
        }
        return v;
    }
};