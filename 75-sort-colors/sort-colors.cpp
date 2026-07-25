class Solution {
public:
    void sortColors(vector<int>& nums) {
        int lp = 0;
        int rp = nums.size() - 1;
        int it = 0; 

        while(it <= rp){
            if(nums[it] == 0){
                nums[it] = nums[lp];
                nums[lp] = 0;
                if(lp == it) it++;
                lp++; 
            }
            else if(nums[it] == 2){
                nums[it] = nums[rp];
                nums[rp] = 2;
                rp--;
            }
            else{
                it++;
            }
        }
    }
};