class Solution
{
public:
    vector<string> answer;
    pair<int, int> getvalue(string s)
    {
        int left = 0;
        int right = 0;
        for (const char a : s)
        {
            if (a == '(')
                left++;
            else if (a == ')')
            {
                if (left == 0)
                    right++;
                else
                    left--;
            }
        }
        return {left, right};
    }
    bool isvalid(string s)
    {
        int count = 0;
        for (const char a : s)
        {
            if (a == '(')
                count++;
            else if (a == ')')
                count--;
            if (count < 0)
                return false;
        }
        return true;
    }
    void backtracking(string s, int start, int left, int right)
    {
        if (left == 0 and right == 0 and isvalid(s))
        {
            answer.push_back(s);
            return;
        }
        for (int i = start; i < s.size(); i++)
        {
            if (i > start and s[i] == s[i - 1])
                continue;
            if (left > 0 and s[i] == '(')
                backtracking(s.substr(0, i) + s.substr(i + 1), i, left - 1, right);
            if (right > 0 and s[i] == ')')
                backtracking(s.substr(0, i) + s.substr(i + 1), i, left, right - 1);
        }
    }
    vector<string> removeInvalidParentheses(string s)
    {
        const auto [left, right] = getvalue(s);
        backtracking(s, 0, left, right);
        return answer;
    }
};