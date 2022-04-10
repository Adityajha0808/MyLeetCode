class Solution {
public:
    bool check_number(string str) {
       if(str[0] == '-') return true;
       for (int i = 0; i < str.length(); i++)
       if(isdigit(str[i]) == false) return false;
          return true;
    }
    int calcSum(vector<int> v) {
        int s = 0;
        for(int i=0; i<v.size(); i++) {
            s += v[i];
        }
        return s;
    }
    int calPoints(vector<string>& a) {
        vector<int> v;
        int sum = 0;
        for(int i=0; i<a.size(); i++) {
            if(check_number(a[i])) {
                v.push_back(stoi(a[i]));
                sum = calcSum(v);
            } else {
                if(a[i] == "+") {
                    int x = v[v.size() - 1] + v[v.size() - 2];
                    v.push_back(x);
                    sum = calcSum(v);
                } else if(a[i] == "D") {
                    sum += 2 * v.back();
                    v.push_back(2 * v.back());
                } else if(a[i] == "C") {
                    sum -= v.back();
                    v.pop_back();
                }
            }
        }
        return sum;
    }
};