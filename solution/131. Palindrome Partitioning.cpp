class Solution {
public:
    vector<vector<string>> answer;
    bool polidrome(string s , int start , int finish)
    {
        while(start < finish)
        {
            if(s[start++] != s[finish--])
            {
                return false;
            }
        }
        return true;
    }
    void bakctracking(string s, int start, vector<string> path)
    {
        if(s.size()== start)
        {
            answer.push_back(path);
            return;
        }
        for(int i =start; i < s.size();i++)
        {
            if(polidrome(s,start ,i))
            {
                path.push_back(s.substr(start,i-start+1));
                bakctracking(s,i+1,path);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>path;
        bakctracking(s,0,path);
        return answer;
    }
};