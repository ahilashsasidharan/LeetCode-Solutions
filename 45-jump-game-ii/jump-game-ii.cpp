class Solution {
public:
    int jump(vector<int>& nums) {
        // Have a maxJmpRange to pick next jump within range of the step you are jumping from
        // (Works since you must always jump from the step 0)
        // Edge Case Unless Size of Arr is 1 then You Are Already at n - 1 index
        // So to Deal with This Start Algo/Loop at index = 1
        // Keep checking within maxJmpRange for which jump to choose
        // Update maxJmpRange once the current one is exceeded using a reach calculated from steps you can take     
        // Note: don't need a reachable since it is assumed the final target is always reachable
        // Also need a count variable for steps taken and can stop once a step is reached that can hit n-1

        //  pair<int, int> step = (0, 0);
        int maxReach = 0;
        int jumps = 0;
        int maxJmpRange = nums[0];

        for(int i = 1; i < nums.size(); i++){
            if(maxJmpRange < i){
                maxJmpRange = maxReach;
                maxReach = 0;
                jumps++;
            }

            if(maxJmpRange >= nums.size() - 1){
                return jumps + 1;
            }

            if(nums[i] + i > maxReach){
                maxReach = nums[i] + i;
            }
        }

        return jumps;

    }
};