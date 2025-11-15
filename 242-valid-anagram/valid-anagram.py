class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        chars = {}
        
        for i in range(len(s)):
            chars[s[i]] = chars.get(s[i], 0) + 1
            chars[t[i]] = chars.get(t[i], 0) - 1

        for val in chars.values():
            if val != 0:
                return False

        return True