class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorRes = 0;
        for(int n : nums){
            xorRes ^= n;
        }
        return xorRes;
    }
};