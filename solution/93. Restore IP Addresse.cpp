class Solution {
public:
    vector<string>answer;
    void backtracking(string s , int start , vector<string>&path)
    {
        if(start == s.size() and path.size()==4)
        {
            answer.push_back(path[0]+'.'+path[1]+'.'+path[2]+'.'+path[3]);
            return;
        }
        if(start == s.size() or path.size()==4) return;
        for(int length =1; length <=3;length++)
        {
            if(start+length > s.size()){
                return;
            }
            if(length > 1 and s[start]=='0') return;
            const string & temp = s.substr(start,length);
            if(stoi(temp) > 255)
                return;
            path.push_back(temp);
            backtracking(s ,start+length,path);
            path.pop_back();
        }
    }
    vector<string> restoreIpAddresses(string s) 
    {
        vector<string>path;
        backtracking(s ,0,path);
        return answer;
    }
};
