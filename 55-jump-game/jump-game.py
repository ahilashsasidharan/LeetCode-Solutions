class Solution:
    def canJump(self, nums: List[int]) -> bool:
      # Set a Target Index
      # If You Can Hit A Target Index that is the New Target Index

        target = len(nums) - 1 

        for i in range(len(nums) - 1, -1, -1):
            if nums[i] >= (target - i):
                target = i

        return not (target)  