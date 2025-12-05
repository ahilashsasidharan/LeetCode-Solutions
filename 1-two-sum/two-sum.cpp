class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> seen;

        for(int i = 0; i < nums.size(); i++){
            int sNum = target - nums[i];
            if(seen.find(sNum) != seen.end()){
                return {seen[sNum], i};
            }
            seen[nums[i]] = i;
        }

        return {};
    }
};