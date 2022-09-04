class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i , int j)
    {
        if(i < 0 or j < 0 or i == grid.size() or j == grid[0].size())
            return 0;
        if(grid[i][j] != 1)
            return 0;
        grid[i][j]=2;
        return 1 + dfs(grid,i+1,j) + dfs(grid,i-1,j) + dfs(grid,i,j+1) + dfs(grid,i,j-1);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        const int row = grid.size();
        const int col = grid[0].size();
        int answer =0;
        for(int i =0; i< row; i++)
        {
            for(int j =0; j < col;j++)
            {
                if(grid[i][j]==1)
                {
                    answer = max(answer,dfs(grid,i,j));
                }
            }
        }
        return answer;
        
    }
};