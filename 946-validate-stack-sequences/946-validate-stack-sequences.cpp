class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        stack<int> st;
        st.push(pushed[0]);
        int j = 0;
        for(int i=1; i<=n; ++i) {
            while(!st.empty() and j < n and st.top() == popped[j]) {
                st.pop();
                j++;
            }
            if(i < n) st.push(pushed[i]);
        }
        return (st.empty() ? true : false);
    }
};