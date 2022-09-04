class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int sum = 0;
        int answer = INT_MIN;
        for (const int n : nums)
        {
            sum += n;
            answer = max(answer, sum);
            sum = max(sum, 0);
        }
        return answer;
    }
};