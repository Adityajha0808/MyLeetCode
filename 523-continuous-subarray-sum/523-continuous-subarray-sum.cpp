class Solution {
public:
    bool checkSubarraySum(vector<int>& a, int k) {
        int sum = 0, tmp = 0;
        unordered_map<int, int> mp;
        for(auto i: a) {
            sum = (sum + i) % k;
            if(mp.find(sum) != mp.end())
                return true;
            mp[tmp]++;
            tmp = sum;
        }
        return false;
    }
};