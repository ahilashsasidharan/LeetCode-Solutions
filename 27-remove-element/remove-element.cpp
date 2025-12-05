class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int rp = nums.size() - 1;
        for(int i = 0; i <= rp; i++){
            if(nums[i] == val){
                while(nums[rp] == val and rp > i)
                    rp--;
                nums[i] = nums[rp];
                rp --;
            }
        }    

        return rp + 1;    
    }
};