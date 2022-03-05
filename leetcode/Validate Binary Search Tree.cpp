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
    bool isValidBST(TreeNode* root) {
        return check(root,NULL,NULL);
    }
    
    bool check(TreeNode* main,TreeNode* left, TreeNode* right)
    {
        if(!main)
            return true;
        if(left && main->val <= left->val || right && main->val >= right->val)
            return false;
        return check(main->left,left,main) && check(main->right,main,right);
    }
};
