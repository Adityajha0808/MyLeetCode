class Solution {
public:
    bool isSameStack(stack<char> stack1, stack<char> stack2) {
        bool flag = true;
        if(stack1.size() != stack2.size()) {
            flag = false;
            return flag;
        }
        while (stack1.empty() == false) {
            if(stack1.top() == stack2.top()) {
                stack1.pop();
                stack2.pop();
            }
            else {
                flag = false;
                break;
            }
        }
        return flag;
    }
    bool backspaceCompare(string s, string t) {
        stack<char> st1;
        for(int i=0; i<s.length(); i++) {
            if(s[i] != '#') {
                st1.push(s[i]);
            } else {
                if(!st1.empty()) st1.pop();
            }
        }
        stack<char> st2;
        for(int i=0; i<t.length(); i++) {
            if(t[i] != '#') {
                st2.push(t[i]);
            } else {
                if(!st2.empty()) st2.pop();
            }
        }
        return (isSameStack(st1, st2) ? true : false);
    }
};