class Solution {
public:
    bool find132pattern(vector<int>& a) {
        int n = a.size(), sec = INT_MIN;
        stack<int> st;
        for(int i=n-1; i>=0; --i) {
            if(a[i] < sec) return true;
            else {
                while(st.size() and a[i] > st.top()) {
                    sec = st.top();
                    st.pop();
                }
            }
            st.push(a[i]);
        }
        return false;
    }
};