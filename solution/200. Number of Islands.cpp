class Solution {
public:
    void dfs(vector<vector<char>>& grid,int i , int j)
    {
        if(i < 0 or j < 0 or i == grid.size() or j == grid[0].size())
            return;
        if(grid[i][j] != '1')
            return;
        grid[i][j]='*'; // already visited
        dfs(grid,i-1,j);
        dfs(grid,i+1,j);
        dfs(grid,i,j-1);
        dfs(grid,i,j+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int answer=0;
        const int row = grid.size();
        const int col = grid[0].size();
        for(int i =0; i < row ; i++)
        {
            for(int j =0; j < col;j++)
            {
                if(grid[i][j]=='1')
                {
                    dfs(grid,i,j);
                    answer++;
                }
            }
        }
        return answer;
    }
};