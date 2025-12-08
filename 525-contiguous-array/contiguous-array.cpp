class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // keep track of the difference between 1s & 0s at each index
        // since we care about the difference between them being 0
        // we can use this at each index to look for a target
        // that could be removed to ensure a 0 subarray
        // only keep track of the leftmost index that has a certian difference 
        // since we want the max subarray length with difference 0
        // i.e. if we have difference 5 - 4 = 1 (need one 0) we can look for difference -1
        unordered_map<int, int> differences;

        // keep track of numbers of ones and zeros to find difference at each index
        int numOnes = 0;
        int numZeros = 0;

        // keep track of the longest contiguous subarray
        int maxLen = 0;

        // initialize remainder 0 to index -1 to deal with case where difference is 0
        differences[0] = -1; 

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1) numOnes++;
            else numZeros++;

            int diff = numOnes - numZeros;

            if(differences.find(diff) != differences.end()){
                if(i - differences[diff] > maxLen){
                    maxLen = i - differences[diff];
                }
            }
            else{
                differences[diff] = i;
            }
        }

        return maxLen;
    }
};