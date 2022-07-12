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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        TreeNode* travel = root;
        vector<vector<int>> ans;
        
        if(!root)
            return ans;
        
        vector<int> node;
        int level = -1;
        while(1)
        {
            travel = root;
            node.clear();
            
            if(level == -1)
            {
                node.push_back(travel->val);
                ans.push_back(node);
                level++;
                continue;
            }
            int start = 0;
            while(start <level && travel)
            {
                travel = travel->left;
                start++;
            }

            if(travel)
            {
                if(travel->left){
                    node.push_back(travel->left->val);
                }
                if(travel->right){
                    node.push_back(travel->right->val);
                }
            }
            start = 0;
            travel = root;
            if(level == 0)
            {
                if(node.size() == 0)
                    break;
                level++;
                ans.push_back(node);
                continue;
            }
            while(start <level && travel)
            {
                travel = travel->right;
                start++;
            }
            if(travel)
            {
                if(travel->left){
                    node.push_back(travel->left->val);
                }
                if(travel->right){
                    node.push_back(travel->right->val);
                }
            }
            
            if(node.size() == 0)
                break;
            ans.push_back(node);
            level++;            
        }
        
        return ans;
    }
};
