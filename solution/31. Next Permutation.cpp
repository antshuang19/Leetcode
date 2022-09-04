class Solution
{
public:
    void reverse(vector<int> &nums, int left, int right)
    {
        while (left < right)
        {
            swap(nums[left++], nums[right--]);
        }
    }
    void nextPermutation(vector<int> &nums)
    {
        int length = nums.size();
        int i;
        for (i = length - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
                break;
        }
        if (i >= 0)
        {
            for (int j = length - 1; j > i; j--)
            {
                if (nums[j] > nums[i])
                {
                    swap(nums[j], nums[i]);
                    break;
                }
            }
        }
        reverse(nums, i + 1, length - 1);
    }
};