class Solution {
public:
    vector<vector<int>> answer;
    void backtracking(vector<int>&nums,int start,vector<int>&path)
    {
        answer.push_back(path);
        for(int i =start;  i < nums.size();i++)
        {
            if( i > start and nums[i] == nums[i-1])
                continue;
            path.push_back(nums[i]);
            backtracking(nums,i+1,path);
            path.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>path;
        backtracking(nums,0,path);
        return answer;
    }
};