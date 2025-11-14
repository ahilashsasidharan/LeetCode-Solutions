class Solution:
    def isPalindrome(self, x: int) -> bool:
        s = str(x)
        # Compare Left to Right Chars and Move Inwards
        for i in range(0, len(s) // 2):
            if s[i] != s[len(s) - 1 - i]:
                return False

        return True
        