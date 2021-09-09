//https://leetcode.com/problems/intersection-of-two-linked-lists/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int sz1 = 0;
        int sz2 = 0;
        ListNode *tempA = headA;
        ListNode *tempB = headB;
        while(tempA!=NULL)
        {
            tempA = tempA->next;
            sz1++;
        }
        while(tempB!=NULL)
        {
            tempB = tempB->next;
            sz2++;
        }
        tempA = headA;
        tempB = headB;
        if(sz1 >= sz2)
        {
            int diff = sz1 - sz2;
            while(diff--)
                tempA = tempA->next;
        }
        else
        {
            int diff = sz2 - sz1;
            while(diff--)
                tempB = tempB->next;
        }
        while(tempA!=NULL)
        {
            if(tempA == tempB)
                return tempA;
            tempA = tempA->next;
            tempB = tempB->next;
        }
        return NULL;
    }
};
