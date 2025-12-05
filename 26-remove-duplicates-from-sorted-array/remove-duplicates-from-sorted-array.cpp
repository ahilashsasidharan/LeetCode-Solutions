class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int prev = nums[0];
        int lp = 1;

        for(int i = 0; i < nums.size(); i++){
            if(prev == nums[i]){
                continue;
            }
            nums[lp] = nums[i];
            prev = nums[i];
            lp++;
        }

        return lp;
    }
};