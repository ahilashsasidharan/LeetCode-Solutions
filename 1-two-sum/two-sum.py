class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        orig = nums.copy()
        nums.sort()
        lp = 0
        rp = len(nums) - 1
        while lp < rp:
            sums = nums[lp] + nums[rp]
            if sums == target:
                if nums[lp] == nums[rp]:
                    return [i for i, x in enumerate(orig) if x == nums[lp]]
                return [orig.index(nums[lp]), orig.index(nums[rp])]
            elif sums > target:
                rp -= 1
            elif sums < target:
                lp += 1