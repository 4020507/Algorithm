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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> v;
        int remain = 0;
        while(l1 && l2)
        {
            int val = l1->val + l2->val + remain;
            remain = val/10;
            v.push_back(val%10);
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1)
        {
            int val = l1->val + remain;
            remain = val/10;
            v.push_back(val%10);
            l1 = l1->next;
        }
        while(l2)
        {
            int val = l2->val + remain;
            remain = val/10;
            v.push_back(val%10);
            l2 = l2->next;
        }
        if(remain > 0)
            v.push_back(remain);
        ListNode * ans = new ListNode();
        ListNode * temp = ans;
        int len = v.size();
        
        for(int i = 0;i<len;i++)
        {
            temp->val = v[i];
            
            if(i != len-1)
            {
                temp->next = new ListNode();
                temp = temp->next;
            }
        }
        
        return ans;
    }
};
