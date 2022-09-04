class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        const int row = grid.size();
        const int col = grid[0].size();
        for(int i =0;i < row; i++)
        {
            for(int j =0; j < col;j++)
            {
                if(i > 0 and j > 0)
                {
                    grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
                }
                else if(i > 0)
                    grid[i][j] += grid[i-1][j];
                else if(j > 0)
                    grid[i][j] += grid[i][j-1];
            }
        }
        return grid[row-1][col-1];
    }
};