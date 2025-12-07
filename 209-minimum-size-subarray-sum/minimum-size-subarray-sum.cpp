class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int lp = 0;
        int minLen = 0;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(sum >= target){
                while(sum >= target){
                    sum -= nums[lp];
                    lp++;    
                }
                if((i + 1 - lp) < minLen or minLen == 0) minLen = i + 2 - lp;
            }
        }
        //((i + 1 - lp) < minLen or minLen == 0)

        return minLen;
    }
};