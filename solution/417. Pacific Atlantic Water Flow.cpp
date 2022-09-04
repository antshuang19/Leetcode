class Solution
{
public:
    void dfs(vector<vector<int>> &heights, vector<vector<bool>> &seen, int i, int j, int h = 0)
    {
        if (i < 0 or j < 0 or i == heights.size() or j == heights[0].size())
            return;
        if (seen[i][j] or heights[i][j] < h)
            return;
        seen[i][j] = true;
        dfs(heights, seen, i + 1, j, heights[i][j]);
        dfs(heights, seen, i - 1, j, heights[i][j]);
        dfs(heights, seen, i, j + 1, heights[i][j]);
        dfs(heights, seen, i, j - 1, heights[i][j]);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        const int row = heights.size();
        const int col = heights[0].size();
        vector<vector<int>> answer;
        vector<vector<bool>> seenP(row, vector<bool>(col));
        vector<vector<bool>> seenA(row, vector<bool>(col));

        for (int i = 0; i < row; i++)
        {
            dfs(heights, seenP, i, 0);
            dfs(heights, seenA, i, col - 1);
        }
        for (int j = 0; j < col; j++)
        {
            dfs(heights, seenP, 0, j);
            dfs(heights, seenA, row - 1, j);
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (seenA[i][j] and seenP[i][j])
                    answer.push_back({i, j});
            }
        }
        return answer;
    }
};