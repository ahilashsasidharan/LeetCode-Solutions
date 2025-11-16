class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        
        lp = 0
        rp = len(numbers) - 1

        while lp < rp:

            if numbers[lp] + numbers[rp] == target:
                return [lp + 1, rp + 1]

            if numbers[lp] + numbers[rp] < target:
                lp += 1

            if numbers[lp] + numbers[rp] > target:
                rp -= 1