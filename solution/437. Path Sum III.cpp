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
    int answer =0;
    void dfs(TreeNode * root, long long int target)
    {
        if(!root) return;
        target -=root->val;
        if(target==0)
            answer++;
        dfs(root->left, target);
        dfs(root->right, target);
    }
    void pathsum(TreeNode * root, int target)
    {
        if(!root)
            return;
        dfs(root, target);
        pathsum(root->left,target);
        pathsum(root->right,target);
        
    }
    int pathSum(TreeNode* root, int targetSum) {
        pathsum(root,targetSum);
        return answer;
    }
};