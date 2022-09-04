class Solution
{
public:
    vector<string> answer;
    void bakctracking(int left, int right, string &path)
    {
        if (left == 0 and right == 0)
        {
            answer.push_back(path);
            return;
        }
        if (left > 0)
        {
            path.push_back('(');
            bakctracking(left - 1, right, path);
            path.pop_back();
        }
        if (right > left)
        {
            path.push_back(')');
            bakctracking(left, right - 1, path);
            path.pop_back();
        }
    }
    vector<string> generateParenthesis(int n)
    {
        string path;
        bakctracking(n, n, path);
        return answer;
    }
};