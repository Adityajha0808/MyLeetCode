class Solution {
public:
     long long int calculate(vector<long long int>& nums) {
  long long int curr = 0;
         long long int mx = INT_MIN;
  for (auto c : nums)
    curr = max(c, curr + c),
    mx = max(mx, curr);
  return mx;
}
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
            long long int n = nums1.size();
    vector<long long int> vec1(n, 0);
    auto vec2 = vec1;
    long long int S1 = 0;
    long long int S2 = 0;
    for(long long int i = 0 ; i<n ;  i++){
    S1 += nums1[i];
    S2 += nums2[i];
    }
    for (long long int i = 0; i < n; i++)
    {
      vec1[i] = nums2[i] - nums1[i];
    }
    for (long long int i = 0; i < n; i++)
    {
      vec2[i] = nums1[i] - nums2[i];
    }
    long long int first = max(S1 + calculate(vec1), S2 - calculate(vec1));
    long long int second = max(S2 + calculate(vec2), S1 - calculate(vec2));
    return max(first , second);
    }
};