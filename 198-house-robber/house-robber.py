class Solution:
    def rob(self, nums: List[int]) -> int:
        DP = [0] * len(nums)

        for i in range(len(nums)):
            if i == 0:
                DP[i] = nums[i]
                continue

            if i == 1:
                DP[i] = max(nums[i], DP[i - 1])
                continue
            
            DP[i] = max(DP[i - 2] + nums[i], DP[i - 1])

        return DP[len(nums) - 1]

             