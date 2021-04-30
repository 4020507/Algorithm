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
    int ans;
    void preorder(TreeNode* node,int count)
    {
        if(node != NULL){
            preorder(node->left,count+1);
            preorder(node->right,count+1);
        }
        if(ans<count-1)
            ans = count-1;
    }
    int maxDepth(TreeNode* root) {
        ans = 0;
        if(root)
            preorder(root,1);
        return ans;
    }
};
