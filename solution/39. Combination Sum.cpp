class Solution {
public:
    vector<vector<int>> answer;
    void backtracking(vector<int>& candidates, int target,vector<int> &path,int start)
    {
        if(target < 0) return;
        if(target == 0){
            answer.push_back(path);
            return ;
        }
        for(int i =start;i < candidates.size();i++)
        {
            path.push_back(candidates[i]);
            backtracking(candidates,target-candidates[i],path,i);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(target ==0) return {};
        vector<int>path;
        backtracking(candidates,target,path,0);
        return answer;
    }
};