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
    TreeNode * prep = nullptr;
    TreeNode * x = nullptr;
    TreeNode * y = nullptr;
    void inorder(TreeNode * root)
    {
        if(!root) return;
        inorder(root->left);
        
        if(prep and root->val < prep->val)
        {
            y = root;
            if(!x)
            {
                x = prep;
            }
            else
                return;
        }
        prep = root;
        inorder(root->right);
    }
    void swap(TreeNode * x, TreeNode * y)
    {
        const int temp = x->val;
        x->val = y->val;
        y->val = temp;
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(x,y);
    }
};