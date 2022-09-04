class Solution
{
public:
    string reverseWords(string s)
    {
        stack<string> stk;
        string temp = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != ' ')
            {
                temp.push_back(s[i]);
            }
            else if (!temp.empty())
            {
                stk.push(temp);
                temp = "";
            }
        }
        if (temp != "")
        {
            stk.push(temp);
            temp = "";
        }
        while (!stk.empty())
        {
            if (temp == "")
            {
                temp = stk.top();
            }
            else
            {
                temp = temp + " " + stk.top();
            }
            stk.pop();
        }
        return temp;
    }
};