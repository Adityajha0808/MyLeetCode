using ll = long long;
class Solution {
public:
    ll minimalKSum(vector<int>& a, int k) {
        map<int,int> mp;
        for(auto i: a) mp[i]++;
        a.clear();
        for(auto i: mp) a.push_back(i.first);
        // sort(a.begin(), a.end());
        ll start = 1, end = 0, res = 0;
        while(k > 0) {
            if(a.size() > end and start == a[end]) {
                start++;
                end++;
            }
            ll fin;
            if(a.size() == end) fin = a.back() + k + 1;
            else fin = a[end];
            while(start < fin and k > 0) {
                res += start;
                start++;
                k--;
            }
        }
        return res;
    }
};