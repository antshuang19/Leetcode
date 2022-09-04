class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            const int middle = (left + right) / 2;
            if (nums[middle] == target)
                return true;
            if (nums[left] == nums[middle] and nums[right] == nums[middle])
            {
                ++left;
                --right;
            }
            else if (nums[left] <= nums[middle])
            {
                if (nums[left] <= target and target < nums[middle])
                {
                    right = middle - 1;
                }
                else
                {
                    left = middle + 1;
                }
            }
            else
            {
                if (nums[middle] < target and target <= nums[right])
                {
                    left = middle + 1;
                }
                else
                {
                    right = middle - 1;
                }
            }
        }
        return false;
    }
};