# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        count = 0
        fp = head
        sp = head
        while  fp != None:
            if count > n:
                sp = sp.next
            if fp.next == None:
                if count + 1 == n:
                    head = sp.next
                else:
                    sp.next = sp.next.next
            
            fp = fp.next
            count += 1

        return head
            