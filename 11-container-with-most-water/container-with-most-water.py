class Solution:
    def maxArea(self, height: List[int]) -> int:
        # Use 2 Pointers Keep Moving the Lower Pointer Keep Track of the Largest Area
        lp = 0 
        rp = len(height) - 1
        mArea = 0

        while lp < rp:
            cArea = min(height[lp], height[rp]) * (rp - lp)

            if cArea > mArea:
                mArea = cArea

            pl = height[lp]
            pr = height[rp]
            
            if height[lp] <= height[rp]:
                while lp < rp and height[lp] <= pl:
                    lp += 1
            else:
                while lp < rp and height[rp] <= pr:
                    rp -= 1

        return mArea