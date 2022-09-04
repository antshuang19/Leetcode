class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int left = 0;
        int right = height.size() - 1;
        int answer = 0;
        while (left < right)
        {
            const int minHeight = min(height[left], height[right]);
            answer = max(answer, minHeight * (right - left));
            if (height[left] < height[right])
            {
                left++;
            }
            else 
            {
                right--;
            }
        }
        return answer;
    }
};