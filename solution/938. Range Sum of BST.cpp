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
    int answer=0;
    void inorder(TreeNode * root , int low , int high)
    {
        if(!root) return;
        inorder(root->left ,low ,high);
        if(root->val >= low and root->val <= high)
            answer += root->val;
        inorder(root->right ,low ,high);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root) return 0;
        inorder(root,low ,high);
        return answer;
    }
};