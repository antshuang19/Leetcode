class Solution
{
public:
    void dfs(vector<vector<char>> &board, int i, int j)
    {
        if (i < 0 or j < 0 or i == board.size() or j == board[0].size())
            return;

        if (board[i][j] != 'O')
            return;

        board[i][j] = '*';
        dfs(board, i - 1, j);
        dfs(board, i + 1, j);
        dfs(board, i, j - 1);
        dfs(board, i, j + 1);
    }
    void solve(vector<vector<char>> &board)
    {
        if (board.empty())
            return;

        const int row = board.size();
        const int col = board[0].size();
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (i * j == 0 or i == row - 1 or j == col - 1)
                    dfs(board, i, j);
            }
        }

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (board[i][j] == '*')
                    board[i][j] = 'O';
                else if (board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};