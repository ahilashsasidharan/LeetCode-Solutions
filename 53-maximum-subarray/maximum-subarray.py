class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        maxSum = nums[0]
        subSum = 0

        for num in nums:
            subSum += num

            if subSum > maxSum:
                maxSum = subSum

            if subSum < 0:
                subSum = 0

        return maxSum