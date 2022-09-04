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
class Solution
{
public:
    vector<vector<int>> answer;
    void backtracking(TreeNode *root, int targetsum, vector<int> &path)
    {
        if (!root)
            return;
        if (root->val == targetsum and !root->left and !root->right)
        {
            path.push_back(root->val);
            answer.push_back(path);
            path.pop_back();
            return;
        }
        path.push_back(root->val);
        backtracking(root->left, targetsum - root->val, path);
        backtracking(root->right, targetsum - root->val, path);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<int> path;
        backtracking(root, targetSum, path);
        return answer;
    }
};