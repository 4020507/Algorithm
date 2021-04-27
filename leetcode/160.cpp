/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    int length(ListNode * trace)
    {
        int count = 0;
        while(trace != NULL)
        {
            trace = trace->next;
            count++;
        }
        return count;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        int A = length(headA);
        int B = length(headB);
        
        if(A == 0 || B == 0)
            return NULL;
        
        int diff = A - B;
        
        if(diff>0)
        {
            while(diff > 0)
            {
                headA = headA->next;
                diff--;
            }
        }
        else
        {
            while(diff<0)
            {
                headB = headB->next;
                diff++;
            }
        }
        
        while(headA != NULL)
        {
            if(headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};
