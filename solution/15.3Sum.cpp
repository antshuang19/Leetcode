class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> answer;
        int size = nums.size();
        sort(begin(nums), end(nums));

        for (int i = 0; i < size; i++)
        {
            if (i > 0 and nums[i] == nums[i - 1])
                continue;
            int left = i + 1;
            int right = size - 1;
            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum > 0)
                {
                    right--;
                }
                else if (sum < 0)
                {
                    left++;
                }
                else
                {
                    vector<int> subset{nums[i], nums[left], nums[right]};
                    answer.push_back(subset);
                    left++;
                    while (left < right and nums[left] == nums[left - 1])
                        left++;
                }
            }
        }
        return answer;
    }
};