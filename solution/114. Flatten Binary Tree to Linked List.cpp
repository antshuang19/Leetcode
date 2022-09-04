/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : 4val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        
        stack<TreeNode*> stk{{root}};
        while(!stk.empty())
        {
            root = stk.top();
            stk.pop();
            if(root->right)
                stk.push(root->right);
            if(root->left)
                stk.push(root->left);
            if(!stk.empty())
                root->right = stk.top();
            root->left = NULL;
        }
        
    }
};