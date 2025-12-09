class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int tIndex = -1;

        // Step 1: Find the Target Using Binary Search
        int lp = 0;
        int rp = nums.size() - 1;
        int mp = 0;
        while(lp <= rp){
            mp = (lp + rp) / 2;
            if(nums[mp] == target){
                tIndex = mp;
                break;
            }
            if(nums[mp] > target){
                rp = mp - 1;
            }
            else if(nums[mp] < target){
                lp = mp + 1;
            }
        }

        if(tIndex == -1) return {-1, -1};

        // Step 2: Find the Left Most Occurence of Target
        // utilize lp from previous loop and mp/tIndex as the rp for this binary search
        int tRP = rp;
        int lefti = -1;
        rp = tIndex;
        while(lp <= rp){
            mp = (lp + rp) / 2;
            if(nums[mp] == target and (mp - 1 < lp or nums[mp - 1] != target)){
                lefti = mp;
                break;
            }
            if(nums[mp] == target){
                rp = mp - 1;
            }
            else if(nums[mp] < target){
                lp = mp + 1;
            }
        }

        // Step 3: Find the Right Most Occurence of Target
        rp = tRP;
        int righti = -1;
        lp = tIndex;
        while(lp <= rp){
            mp = (lp + rp) / 2;
            if(nums[mp] == target and (mp + 1 > rp or nums[mp + 1] != target)){
                righti = mp;
                break;
            }
            if(nums[mp] > target){
                rp = mp - 1;
            }
            else if(nums[mp] == target){
                lp = mp + 1;
            }
        }

        return {lefti, righti};
    
    }
};