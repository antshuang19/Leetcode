class Solution {
public:
    bool isValid(string s) 
    {
        if(s.empty()) return true;
        stack<char> stk;
        for(int i =0; i < s.size();i++)
        {
            if(s[i] == '(' or s[i]=='{' or s[i]=='[')
                stk.push(s[i]);
            else 
            {
                if(stk.empty()) return false;
                char tmp = stk.top();
                if((s[i]=='}' and  tmp =='{') or (s[i]==']' and  tmp =='[' ) or (s[i]==')' and  tmp =='('))
                    stk.pop();
                else return false;
                
            }
        }
        if(stk.empty()) return true;
        return false;
    }
};