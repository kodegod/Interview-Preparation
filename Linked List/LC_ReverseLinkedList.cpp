//https://leetcode.com/problems/reverse-linked-list/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr!=NULL)
        {
            ListNode* new_curr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = new_curr;
        }
        return prev;
    }
};
