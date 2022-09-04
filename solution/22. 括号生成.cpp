class Solution {
public:
    vector<string>answer;
    void backtracking(int left, int right, string &path)
    {
        if(left== 0 and right ==0 )
        {
            answer.push_back(path);
            return ;
        }
        if(left > 0)
        {
            path.push_back('(');
            backtracking(left-1,right,path);
            path.pop_back();
        }
        if(left < right)
        {
            path.push_back(')');
            backtracking(left,right-1,path);
            path.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) 
    {
        if(n == 0) return {};
        string path;
        backtracking(n,n,path);
        return answer;
    }
};