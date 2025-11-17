class Solution:
    def search(self, nums: List[int], target: int) -> int:
        lp, rp = 0, len(nums) - 1

        while lp <= rp:
            mp = (lp + rp) // 2

            if target == nums[mp]:
                return mp
            
            # mid is in the left side
            if nums[lp] <= nums[mp]:
                if nums[lp] > target or nums[mp] < target:
                    lp = mp + 1
                else:
                    rp = mp - 1
            else:
                if nums[rp] < target or nums[mp] > target:
                    rp = mp - 1
                else:
                    lp = mp + 1
        
        return -1
