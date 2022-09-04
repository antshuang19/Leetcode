class Solution
{
public:
    int trap(vector<int> &height)
    {
        const int n = height.size();
        vector<int> left(n);
        vector<int> right(n);
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
                left[i] = height[i];
            else
                left[i] = max(height[i], left[i - 1]);
        }
        for (int i = n - 1; i >= 0; i--)
        {
            right[i] = i == n - 1 ? height[i] : max(height[i], right[i + 1]);
        }
        int answer = 0;
        for (int i = 0; i < n; i++)
        {
            answer += min(left[i], right[i]) - height[i];
        }
        return answer;
    }
};