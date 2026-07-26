class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int LP = 0;
        int RP = nums.size() - 1;

        // to find the shortest unsorted continuous subarray
        // you need to find from left the longest continous increasing subarray
        // and from right the longest decreasing subarray
        // then go through the array and step the pointer back
        // once you for LP find a number smaller than it and RP bigger than it

        while(LP < nums.size() - 1 && nums[LP] <= nums[LP + 1]){
            LP++;
        }

        while(RP > 0 && nums[RP] >= nums[RP - 1]){
            RP--;
        }

        if(LP >= RP) return 0;

        for(int i = 0; i < nums.size(); i++){
            while(i > LP && LP >= 0 && nums[LP] > nums[i]){
                LP--;
            }

            while(i < RP && RP < nums.size() && nums[RP] < nums[i]){
                RP++;
            }
        }

        return RP - LP - 1;
    }
};