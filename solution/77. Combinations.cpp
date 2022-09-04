class Solution
{
public:
    vector<vector<int>> answer;
    void backtracking(int n, int k, int start, vector<int> &path)
    {
        if (path.size() == k)
        {
            answer.push_back(path);
            return;
        }
        for (int i = start; i <= n; i++)
        {
            path.push_back(i);
            backtracking(n, k, i + 1, path);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k)
    {
        if (k == 0)
            return {};
        vector<int> path;
        backtracking(n, k, 1, path);
        return answer;
    }
};