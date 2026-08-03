/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // make a fast and slow pointer
        // to determine if odd or even # of nodes 
        // if it ends on a node that's next node is a nullptr then it's even
        // if the next node has a value but the next nodes next node is a nullptr so it ends then it's odd
        // based on this if it is odd your slow ptr will be in the middle so you can include that as the next for both
        // and make it's pointer a nullptr
        // while if it's even you make the current ptr you are on a nullptr and you start reversing at the next node
        // making it's next ptr a nullptr as well

        ListNode* fastptr = head;
        ListNode* slowptr = head;

        while(fastptr->next != nullptr && fastptr->next->next != nullptr){
            fastptr = fastptr->next->next;
            slowptr = slowptr->next;
        }

        ListNode* prev = nullptr;
        ListNode* reverseIt = slowptr->next;

        slowptr->next = nullptr;

        if(fastptr->next == nullptr){
            prev = slowptr;
        }

        while(reverseIt != nullptr){
            ListNode* temp = reverseIt->next;
            reverseIt->next = prev;
            prev = reverseIt;
            reverseIt = temp;
        }

        ListNode* leftptr = head;
        ListNode* rightptr = prev;

        while(leftptr != nullptr && rightptr != nullptr){
            if(leftptr->val != rightptr->val) return false;
            
            leftptr = leftptr->next;
            rightptr  = rightptr->next;
        }

        return true;
    }
};