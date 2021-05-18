/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


class Solution {
public:
    int val1[1000];
    int count1;
    int count2;
    int val2[1000];
    void preorder(TreeNode * curr)
    {
        if(curr){
            val1[count1] = curr->val;
            count1++;
            preorder(curr->left);
            preorder(curr->right);
        }
        else
        {
            val1[count1] = 0;
            count1++;
        }
    }
    
    void preorder2(TreeNode * curr)
    {
        if(curr){
            val2[count2] = curr->val;
            count2++;
            preorder2(curr->right);
            preorder2(curr->left);
        }
        else
        {
            val2[count2] = 0;
            count2++;
        }
    }
    bool isSymmetric(TreeNode* root) {
        TreeNode * curr = root->left;
        
        count1 = 1;
        if(curr != NULL){
            val1[0] = curr->val;
            preorder(curr);
        }

        
        count2 = 1;
        curr = root->right;
        
        if(curr != NULL){
            val2[0] = curr->val;
            preorder2(curr);
        }
        
        if(count1 != count2)
        {
            return false;
        }
        
        int start = 0;
        while(start < count1)
        {
            if(val1[start] != val2[start])
                return false;
            start++;
        }
        return true;
    }
};
