class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        output = [0] * len(nums) 
        currProd = 1

        for i in range(len(nums)):
            if i == 0:
                output[i] = 1
                continue
            
            currProd = currProd * nums[i - 1]
            output[i] = currProd

        for i in range(len(nums)-1, -1, -1):
            if i == len(nums) - 1:
                currProd = 1
                output[i] *= currProd
                continue
            
            currProd = currProd * nums[i + 1]
            output[i] *= currProd

        return output
