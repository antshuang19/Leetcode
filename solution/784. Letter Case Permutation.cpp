class Solution {
public:
    vector<string> answer;
    void backtracking(string s, int start)
    {
        if(start == s.size())
        {
            answer.push_back(s);
            return;
        }
        if(isdigit(s[start]))
        {
            backtracking(s,start+1);
            return;
        }
        s[start]=tolower(s[start]);
        backtracking(s,start+1);
        s[start]=toupper(s[start]);
        backtracking(s,start+1);
    }
    vector<string> letterCasePermutation(string s) {
        backtracking(s,0);
        return answer;
    }
}; 