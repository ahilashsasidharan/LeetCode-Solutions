class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> seen;

        for(int num : nums){
            seen.insert(num);
        }

        // loop through the array only counting sequence length for candidates

        int maxCount = 0;

        for(int cand : seen){
            int count = 1;

            if(seen.contains(cand - 1)) continue;

            while(seen.contains(cand + count)) count++;

            if(count > maxCount) maxCount = count;
        }

        return maxCount;
    }
};