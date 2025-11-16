class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        triples =[]
        prev = None
        nums.sort()

        for i in range(len(nums)):

            if prev != None and prev == nums[i]:
                continue

            if nums[i] > 0: 
                print(nums[i])
                break
            
            prev = nums[i]

            lp = i + 1
            rp = len(nums) - 1
            lprev = None
            rprev = None
            
            target = 0 - nums[i]

            while lp < rp:

                s = nums[lp] + nums[rp]

                if s == target:
                    print("lp: " + str(lp) + " rp: " + str(rp))
                    triples.append([nums[i], nums[lp], nums[rp]])
                    lprev = nums[lp]
                    while lprev == nums[lp] and lp < len(nums) - 1:
                        lp += 1
                    rprev = nums[rp]
                    while rprev == nums[rp] and rp > 0:
                        rp -= 1
                elif s < target:
                    lprev = nums[lp]
                    while lprev == nums[lp] and lp < len(nums) - 1:
                        lp += 1
                else:
                    rprev = nums[rp]
                    while rprev == nums[rp] and rp > 0:
                        rp -= 1

        return triples


