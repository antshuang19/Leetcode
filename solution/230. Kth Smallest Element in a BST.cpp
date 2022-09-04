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
    int count_node(TreeNode * root)
    {
        if(!root) return 0;
        return 1+ count_node(root->left)+count_node(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        const int leftcount = count_node(root->left);
        if(leftcount == k -1)
        {
            return root->val;
        }
        if(leftcount >= k)
        {
            return kthSmallest(root->left,k);
        }
        return kthSmallest(root->right,k-1- leftcount);
    }
};