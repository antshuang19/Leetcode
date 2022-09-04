class Solution
{
public:
    int sum = 0;
    bool backtracking(vector<int> &nums, int start, int k, int target, vector<bool> &seen)
    {
        if (k == 0)
            return true;
        if (sum == target)
            return backtracking(nums, 0, k - 1, 0, seen);
        if (start >= nums.size())
            return false;
        for (int i = start; i < nums.size(); i++)
        {
            if (!seen[i] and target + nums[i] <= sum)
            {
                seen[i] = true;
                if (backtracking(nums, i + 1, k, target + nums[i], seen))
                    return true;
                seen[i] = false;
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        sum = accumulate(begin(nums), end(nums), 0);
        if (sum % k != 0)
            return false;
        sum = sum / k;
        sort(begin(nums), end(nums));
        if (nums[nums.size() - 1] > sum)
            return false;
        vector<bool> seen(nums.size(), false);
        return backtracking(nums, 0, k, 0, seen);
    }
};