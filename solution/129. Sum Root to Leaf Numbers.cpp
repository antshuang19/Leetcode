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
    vector<int> answer;
    void inorder_transversal(TreeNode * root, int path)
    {
        if(!root) return;
        if(!root->left and !root->right)
        {
            path = path*10 + root->val;
            answer.push_back(path);
            return;
        }
        path = path*10 + root->val;
        inorder_transversal(root->left,path);
        inorder_transversal(root->right,path);
    }
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        inorder_transversal(root,0);
        int ans =0;
        for(int i =0; i < answer.size();i++)
        {
            ans += answer[i];
        }
        return ans;
    }
};