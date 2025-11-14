class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        if n == 0:
            return False

        if n == 1:
            return True
        
        div = n
        while div != 1:
            if div % 2 != 0:
                return False
            div = div / 2
        
        return True