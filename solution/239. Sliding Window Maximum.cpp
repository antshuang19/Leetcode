class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> answer;
        deque<int> q;
        for (int i = 0; i < nums.size(); i++)
        {
            while (!q.empty() and q.back() < nums[i])
                q.pop_back();
            q.push_back(nums[i]);
            if (i >= k and q.front() == nums[i - k])
                q.pop_front();
            if (i >= k - 1)
                answer.push_back(q.front());
        }
        return answer;
    }
};