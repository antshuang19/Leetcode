class Solution
{
public:
    vector<vector<int>> answer;
    void backtracking(vector<int> &candidates, int target, int start, vector<int> &path)
    {
        if (target < 0)
            return;
        if (target == 0)
        {
            answer.push_back(path);
            return;
        }
        for (int i = start; i < candidates.size(); i++)
        {
            if (i > start and candidates[i] == candidates[i - 1])
                continue;
            path.push_back(candidates[i]);
            backtracking(candidates, target - candidates[i], i + 1, path);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        if (target == 0)
            return {};
        vector<int> path;
        sort(begin(candidates), end(candidates));
        backtracking(candidates, target, 0, path);
        return answer;
    }
};