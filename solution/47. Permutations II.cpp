class Solution {
public:
    vector<vector<int>> answer;
    void backtracking(vector<int> &nums, vector<bool> &visit, vector<int> &path)
    {
        if (path.size() == nums.size())
        {
            answer.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (visit[i])
                continue;
            if(i > 0 and nums[i]==nums[i-1] and visit[i-1])
                continue;
            path.push_back(nums[i]);
            visit[i] = true;
            backtracking(nums, visit, path);
            visit[i] = false;
            path.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int total = nums.size();
        vector<bool> visit(total, false);
        vector<int> path;
        if (total == 0)
            return {};
        sort(begin(nums),end(nums));
        backtracking(nums, visit, path);
        return answer;
    }
};