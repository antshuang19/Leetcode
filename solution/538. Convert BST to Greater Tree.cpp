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
    void Reverse_inorder(TreeNode * root, int & prefix){
        if(!root) return;
        Reverse_inorder(root->right, prefix);
        prefix += root->val;
        root->val = prefix;
        Reverse_inorder(root->left,prefix);
    }
    TreeNode* convertBST(TreeNode* root) 
    {
        if(!root) return root;
        int prefix =0;
        Reverse_inorder(root,prefix);
        return root;
    }
};