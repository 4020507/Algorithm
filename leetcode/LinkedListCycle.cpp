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
    bool hasCycle(ListNode *head) {
        
        if(head == NULL || head->next == NULL)
        {
            return false;
        }
        
        ListNode * next1 = head;
        ListNode * next2 = head;
        
        while(next2->next != NULL && next2->next->next != NULL)
        {
            next1 = next1->next;
            next2 = next2->next->next;
            if(next1 == next2)
            {
                return true;
            }
        }
        return false;
    }
};
