class Solution:
    def countBits(self, n: int) -> List[int]:
        DP = [0] * (n + 1)
        offset = 1

        for i in range(n + 1):
            if i == 0:
                DP[i] = 0
                continue

            if offset * 2 == i:
                offset = i

            DP[i] = 1 + DP[i - offset]
        
        return DP

            
            