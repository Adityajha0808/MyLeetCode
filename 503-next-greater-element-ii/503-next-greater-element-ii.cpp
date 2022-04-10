class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& a) {
        int n = a.size();
        stack<int> st;
        vector<int> v(n, -1);
        for(int i=0; i<n*2; ++i) {
            while(!st.empty() and a[st.top()] < a[i%n]) {
                v[st.top()] = a[i%n];
                st.pop();
            }
            st.push(i%n);
        }
        return v;
    }
};