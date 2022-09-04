class Solution {
public:
    bool backtracking(vector<vector<char>>& board, string word, int start,int i , int j)
    {
        if(i < 0 or j < 0 or i == board.size() or j == board[0].size())
            return false;
        if(board[i][j] != word[start] or board[i][j]=='*')
            return false;
        if(start == word.size()-1)
            return true;
        char temp = board[i][j];
        board[i][j]='*';
        const bool answer = backtracking(board,word,start+1,i+1,j) +
                            backtracking(board,word,start+1,i-1,j) +
                            backtracking(board,word,start+1,i,j+1) +
                            backtracking(board,word,start+1,i,j-1) ;
        board[i][j]= temp;
        return answer;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i =0; i < board.size();i++)
        {
            for(int j =0; j < board[0].size();j++)
            {
                if(backtracking(board,word,0,i,j))
                    return true;
            }
        }
        return false;
    }
};