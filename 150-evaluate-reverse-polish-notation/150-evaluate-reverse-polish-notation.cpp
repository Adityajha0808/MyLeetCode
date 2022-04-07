class Solution {
public:
    bool checkOperand(string s) {
        return ((s == "+" || s == "-" || s == "*" || s == "/") ? false : true);
    }
    int evalRPN(vector<string>& a) {
        stack<int> s;
        for(int i=0; i<a.size(); i++) {
            if(checkOperand(a[i])) {
                s.push(stoi(a[i]));
            } else {
                int x = s.top();
                s.pop();
                int y = s.top();
                s.pop();
                if(a[i] == "+") s.push(y+x);
                else if(a[i] == "-") s.push(y-x);
                else if(a[i] == "*") s.push(y*x);
                else if(a[i] == "/") s.push(y/x);
            }
        }
        return s.top();
    }
};