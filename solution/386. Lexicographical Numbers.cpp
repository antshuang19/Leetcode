class Solution
{
public:
    vector<int> answer;
    void dfs(int start, int n)
    {
        if (start > n)
            return;
        answer.push_back(start);
        dfs(start * 10, n);
        if (start % 10 != 9)
        {
            dfs(start + 1, n);
        }
    }
    vector<int> lexicalOrder(int n)
    {
        dfs(1, n);
        return answer;
    }
};