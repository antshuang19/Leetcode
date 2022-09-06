class Solution
{
public:
    int scoreOfParentheses(string s)
    {
        int answer = 0;
        int layer = 0;
        for (int i = 0; i + 1 < s.size(); i++)
        {
            const char a = s[i];
            const char b = s[i + 1];
            if (a == '(' and b == ')')
                answer += 1 << layer;
            layer += a == '(' ? 1 : -1;
        }
        return answer;
    }
};