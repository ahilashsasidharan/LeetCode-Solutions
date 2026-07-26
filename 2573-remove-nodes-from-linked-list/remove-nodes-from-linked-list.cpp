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
    ListNode* removeNodes(ListNode* head) {
        // treat this as a montonic decreasing stack
        std::stack<ListNode*> nodes;

        // if stack is empty push onto it
        // if top of stack is smaller pop till that is not true than push
        // if top is larger than just push

        while(head != nullptr){ 
            while(!nodes.empty() && nodes.top()->val < head->val) nodes.pop();

            nodes.push(head);

            head = head->next;
        }

        // construct the linked list from stack

        while(!nodes.empty()){
            ListNode* temp = head;
            head = nodes.top();
            nodes.pop();

            head->next = temp;
        }

        return head; 
    }
};