class Solution {
public:
    vector<string> answer;
    const vector<string>digitletter{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void dfs(string &digits,int i , string & path)
    {
        if(i == digits.size())
        {
            answer.push_back(path);
            return;
        }
        for(auto abjad : digitletter[digits[i]-'0'])
        {
            path.push_back(abjad);
            dfs(digits,i+1,path);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        string path;
        dfs(digits,0,path);
        return answer;
    }
};