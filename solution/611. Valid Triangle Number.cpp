class Solution
{
public:
    int triangleNumber(vector<int> &nums)
    {
        if (nums.size() < 3)
            return 0;
        int answer = 0;
        sort(begin(nums), end(nums));
        for (int i = nums.size() - 1; i > 1; i--)
        {
            int left = 0;
            int right = i - 1;
            while (left < right)
            {
                if (nums[left] + nums[right] > nums[i])
                {
                    answer += right - left;
                    right--;
                }
                else
                {
                    left++;
                }
            }
        }
        return answer;
    }
};