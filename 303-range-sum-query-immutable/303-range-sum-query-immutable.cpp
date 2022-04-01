class NumArray {
public:
    vector<int> v;
    NumArray(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++) {
            if(!i) v.push_back(nums[i]);
            else v.push_back(nums[i]+v.back());
        }
    }
    
    int sumRange(int l, int r) {
        int x = v[r];
        if(!l) return x;
        return x-v[l-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */