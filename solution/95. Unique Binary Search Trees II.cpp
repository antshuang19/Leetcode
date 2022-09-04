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
    vector<TreeNode*> backtracking(int min,int max)
    {
        if(min > max)
        {
            return {nullptr};
        }
        vector<TreeNode*>answer;
        for(int i = min; i <= max;i++)
        {
            for(TreeNode * left : backtracking(min,i-1))
            {
                for(TreeNode * right : backtracking(i+1, max))
                {
                    answer.push_back(new TreeNode(i));
                    answer.back()->left=left;
                    answer.back()->right= right;
                }
            }
        }
        return answer;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n==0)
        {
            return {};
        }
        return backtracking(1,n);
    }
};