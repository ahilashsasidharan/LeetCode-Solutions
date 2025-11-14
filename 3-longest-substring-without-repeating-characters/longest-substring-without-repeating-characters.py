class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        # Use a Queue When A Duplicate is Found in the Queue Pop Till the Dupe is Found
        # Then Add Dupe and Continue
        queue = []
        count = 0

        for c in s:
            if c in queue:
                if len(queue) > count:
                    count = len(queue)
                res = queue.pop(0)
                while c != res:
                    res = queue.pop(0)
            
            queue.append(c)

        if count < len(queue):
            count = len(queue)
        
        return count


