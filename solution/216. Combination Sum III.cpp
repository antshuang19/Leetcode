class Solution {
public:
    vector<vector<int>> answer;
    void backtracking(int k ,int start,int n , vector<int> &path)
    {
        if(k == 0 and n ==0)
        {
            answer.push_back(path);
            return;
        }
        if(k == 0 and n != 0) return;
        for(int i=start; i <= 9;i++)
        {
            path.push_back(i);
            backtracking(k-1 ,i+1,n-i ,path);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> path;
        backtracking(k,1,n,path);
        return answer;
    }
};