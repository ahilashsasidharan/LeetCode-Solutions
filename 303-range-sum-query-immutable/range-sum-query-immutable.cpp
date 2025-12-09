class NumArray {
public:
    vector<int> nums;
    vector<int> prefixes;

    NumArray(vector<int>& nums) {
        this->nums = nums;
        int sum = 0;
        prefixes.push_back(0);
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            prefixes.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        return prefixes[right + 1] - prefixes[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */