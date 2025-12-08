class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // keep track of remainders of each prefix sum when dividing by k
        // treat this as somewhat of a TwoSum problem using this idea:
        // if we have 2 points with the same remainder in the array
        // then in between those points must be a multiple of k
        // so the remainder calculated is our target and we add each 
        // non-added remainder to the map keeping only the most left to maximize length
        unordered_map<int, int> remainders;

        // initialize remainder 0 to -1 to deal with the first index being divisible
        // or other indexes having a remainder of 0
        remainders[0] = -1;

        // keep track of sum
        int sum = 0;

        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            int target = sum % k;
            if(remainders.find(target) != remainders.end()){
               if(i - remainders[target] >= 2){
                return true;
               } 
            }
            else{
                remainders[target] = i;
            }
        }
        return false;
    }
};