class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int prev = nums[0];
        int count = 1;
        
        while(count < nums.size()){
            if(prev == nums[count]){
                nums.erase(nums.begin() + count);
                continue;
            }
            prev = nums[count];
            count++;
        }

        return nums.size();
    }
};