class Solution {
public:
    vector<vector<int>>answer;
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<int>path;
        DFS(nums,0,path);
        return answer;
    }
    void DFS (const vector<int>&nums,int start , vector<int>&path)
    {
        answer.push_back(path);
        for(int i = start; i < nums.size();i++)
        {
            path.push_back(nums[i]);
            DFS(nums,i+1,path);
            path.pop_back();
        }
    }
};