class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // keep track of the number of valid subarrays that equal k
        int numSubArr = 0;
        // keep track of index 0 to i sum in for loop 
        int sum = 0;
        // keep track of the number of prefixes that sum to a certain number
        // then once you reach a index do k - arrSum checking if any previous prefixes can be used
        // add that amount to numSubArr as that is the amount of additional subarrays you can add
        // initialize 0 to 1 so that if the subArr equals k it will be counted as 1 instance
        unordered_map<int, int> prefixes;
        prefixes[0] = 1;

        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            int target = sum - k;
            if(prefixes.find(target) != prefixes.end()){
                numSubArr += prefixes[target];
            }
            prefixes[sum] += 1;
        }

        return numSubArr;
    }
};