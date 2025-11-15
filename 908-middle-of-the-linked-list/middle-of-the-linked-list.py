# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # Use Fast & Slow Pointer Approach
        middle = head
        index = 0

        while head != None:
            head = head.next
            index += 1
            if index % 2 == 0:
                middle = middle.next
            
        return middle