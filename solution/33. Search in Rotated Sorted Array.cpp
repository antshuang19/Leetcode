class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int answer = -1;
        while (left <= right)
        {
            const int mid = (left + right) / 2;
            if (nums[mid] == target)
            {
                answer = mid;
                break;
            }
            else if (nums[left] <= nums[mid])
            {
                if (nums[left] <= target and target < nums[mid])
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else
            {
                if (nums[mid] < target and target <= nums[right])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
        }
        return answer;
    }
};