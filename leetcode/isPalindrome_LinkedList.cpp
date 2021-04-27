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
    
    int length(ListNode * h)
    {
        int count = 0;
        while(h != NULL)
        {
            h = h->next;
            count++;
        }
        return count;
    }
    
    bool isPalindrome(ListNode* head) {
        
        int len = length(head);
        
        if(len == 0)
            return false;
        if(len == 1)
            return true;
        
        stack<int> q;
        
        int count = 0;
        
        while(count<len/2)
        {   
            q.push(head->val);
            head = head->next;
            count++;
        }
        
        if(len%2 == 1)
            head = head->next;
        
        bool possible = true;
        while(head != NULL)
        {
            if(q.top() != head->val)
            {
                possible = false;
                break;
            }
            q.pop();
            head = head->next;
            
        }
        
        return possible;
    }
};
