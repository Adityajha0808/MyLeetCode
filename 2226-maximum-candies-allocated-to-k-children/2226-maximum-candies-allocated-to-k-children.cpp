using ll = long long;
class Solution {
public:
    bool zoran(vector<int>& a, ll k, ll m) {
        ll c = 0;
        if(m == 0) return 1;
        for(auto& i: a) c += i/m;
        return c >= k;
    }
    int maximumCandies(vector<int>& a, ll k) {
        ll sum = accumulate(a.begin(),a.end(), 0LL);
        ll minm = *min_element(a.begin(), a.end());
        ll cnt = count(a.begin(), a.end(), minm);
        if(sum <= k) return sum/k;
        ll l = 0, r = sum, mid, res;
        while(l <= r) {
            ll mid = l + (r - l)/2;
            if(zoran(a,k,mid))
                l = mid+1;
            else
                r = mid-1;
        }
        return r;
        
    }
};