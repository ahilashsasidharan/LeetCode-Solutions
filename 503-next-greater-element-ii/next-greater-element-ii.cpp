class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> inds;
        vector<int> result(nums.size(), -1);
        inds.push(0);

        for(int i = 1; i < nums.size(); i++){
            while(!inds.empty() and nums[inds.top()] < nums[i]){
                result[inds.top()] = nums[i];
                inds.pop();
            }
            inds.push(i);
        }

        for(int i = 0; i < nums.size(); i++){
            while(!inds.empty() and nums[inds.top()] < nums[i]){
                result[inds.top()] = nums[i];
                inds.pop();
            }
        }

        return result;
    }
};