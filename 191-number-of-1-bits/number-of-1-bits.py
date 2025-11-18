class Solution:
    def hammingWeight(self, n: int) -> int:
        
        weight = 0

        for i in range(32):
            if (n) & 1:
                weight += 1
            n = n >> 1

        return weight