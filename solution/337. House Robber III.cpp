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
    struct Tree{
        int rob_value;
        int not_rob_value;
    };
    Tree rob_or_not(TreeNode * root)
    {
        if(!root) return{0,0};

        const Tree left = rob_or_not(root->left);
        const Tree right = rob_or_not(root->right);

        return {root->val+left.not_rob_value+right.not_rob_value
                ,max(left.rob_value,left.not_rob_value)
                +max(right.not_rob_value,right.rob_value)};

    }
    int rob(TreeNode* root) {
        if(!root) return 0;
        const auto&[rob,not_rob] = rob_or_not(root);
        return max(rob, not_rob);
    }
};