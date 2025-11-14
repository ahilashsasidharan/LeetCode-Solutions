# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head == None or head.next == None:
            return head
        prevNode = head
        currNode = head.next
        prevNode.next = None
        while currNode != None: 
            temp = currNode.next
            currNode.next = prevNode
            prevNode = currNode
            currNode = temp

        return prevNode