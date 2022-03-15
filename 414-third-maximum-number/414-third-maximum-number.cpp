class Solution {
public:
    int thirdMax(vector<int>& a) {
        int n = a.size();
        set<int> s;
        for(int i=0; i<n; ++i) {
            s.insert(a[i]);
            if(s.size() > 3) {
                s.erase(s.begin());
            }
        }
        return (s.size() < 3 ? *s.rbegin() : *s.begin());
    }
};