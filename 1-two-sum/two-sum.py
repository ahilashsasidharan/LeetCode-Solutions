class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        seen = {}

        for i, num in enumerate(nums):
            sNum = target - num
            if sNum in seen:
                return [seen[sNum], i]
            seen[num] = i