# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """

        if head == None or head.next == None:
            return

        # Find the end and middle left of the list
        sp = head
        fp = head
        while fp.next != None and fp.next.next != None:   
            sp = sp.next
            fp = fp.next.next

        print(f'sp: {sp.val} and fp: {fp.val}')

        # Reverse Linked List
        forw = sp.next
        sp.next = None
        prev = None

        while forw != None:
            temp = forw.next
            forw.next = prev
            prev = forw
            forw = temp

        print(f'prev: {prev.val}')

        # Interlace the Two Lists
        rhead = prev
        thead = head

        while rhead != None:
            temp = thead.next
            thead.next = rhead
            rtemp = rhead.next
            rhead.next = temp
            rhead = rtemp
            thead = temp

        print("end")

            

