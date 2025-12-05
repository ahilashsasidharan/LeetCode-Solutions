class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int lSum = 0;
        int rSum = std::accumulate(nums.begin() + 1, nums.end(), 0);

        for(int i = 0; i < nums.size() - 1; i++){
            if(lSum == rSum){
                return i;
            }
            lSum += nums[i];
            rSum -= nums[i + 1];
        }
        if(lSum == rSum) return nums.size() - 1;
        return -1;
    }
};