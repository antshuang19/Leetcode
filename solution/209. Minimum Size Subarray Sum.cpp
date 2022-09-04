class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int answer = INT_MAX;
        int sum = 0;
        for (int left = 0, right = 0; right < nums.size(); right++)
        {
            sum += nums[right];
            while (sum >= target)
            {
                answer = min(answer, right - left + 1);
                sum = sum - nums[left++];
            }
        }
        return answer < INT_MAX ? answer : 0;
    }
};