# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        l3 = None
        prev = None
        carry = 0
        while(l1 != None or l2 != None):
            v1 = v2 = 0
            if(l1 != None):
                v1 = l1.val
                l1 = l1.next
            if(l2 != None):
                v2 = l2.val 
                l2 = l2.next

            r3 =  v1 + v2 + carry
            v3 = r3 % 10
            carry = r3 // 10

            if l3 == None:
                l3 = ListNode(v3)
                temp = l3
            else:
                temp = ListNode(v3)
                prev.next = temp 

            prev = temp

        if carry != 0:
            prev.next = ListNode(carry)

        return l3