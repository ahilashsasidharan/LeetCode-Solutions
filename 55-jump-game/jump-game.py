class Solution:
    def canJump(self, nums: List[int]) -> bool:
      # Set a Target Index (end of array)
      # Then Go Backwards to See if It is Reachable From the Previous Index
      # If You Can Hit A Target Index that is the New Target Index
      # Since if you can get to it you can get to the previous target
      # The Aim is to Get to 0 meaning you can reach the final target from 0\
      # Since it Can Reach Previous Targets that Can Reach the End 

        target = len(nums) - 1 

        for i in range(len(nums) - 1, -1, -1):
            if nums[i] >= (target - i):
                target = i

        # 0 returns False, Other integer return True so flip it to return the correct result + make it boolean
        return not (target)  