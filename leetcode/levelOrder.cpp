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
    vector<vector<int>> v;
    
    void order(TreeNode * node, int curr)
    {
        if(node)
        {
            if(v.size() == curr)
            {
                v.push_back(vector<int>());
            }
            v[curr].push_back(node->val);
            order(node->left,curr+1);
            order(node->right,curr+1);
        }
        
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        order(root,0);
        return v;
    }
};
