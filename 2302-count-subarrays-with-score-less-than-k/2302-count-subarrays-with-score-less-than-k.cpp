using ll = long long;
class Solution {
public:
    long long countSubarrays(vector<int>& a, ll k) {
        ll n = a.size(), start = 0, end = 0, cnt = 0, sum = a[0], run = 1;
        while(start < n and end < n) {
            if((ll)sum * run < k) {
                end++;
                if(end >= start) cnt += end - start;
                if(end < n) {
                    sum += a[end];
                    run++;
                }
            } else {
                sum -= a[start];
                run--;
                start++;
            }
        }
        return cnt;
    }
};