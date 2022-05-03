class Solution {
public:
    int findUnsortedSubarray(vector<int>& a) {
        int n = a.size(), l = n, r = 0;
        stack<int> st;
        for(int i=0; i<n; ++i) {
            while(st.size() and a[st.top()] > a[i]) {
                l = min(l, st.top());
                st.pop();
            }
            st.push(i);
        }
        st.empty();
        for(int i=n-1; i>=0; --i) {
            while(st.size() and a[st.top()] < a[i]) {
                r = max(r, st.top());
                st.pop();
            }
            st.push(i);
        }
        if(r - l <= 0) return 0;
        return r - l + 1;
    }
};