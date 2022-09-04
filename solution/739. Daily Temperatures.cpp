class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        vector<int> answer(temperatures.size());
        stack<int> stk;
        for (int i = 0; i < temperatures.size(); i++)
        {
            while (!stk.empty() and temperatures[stk.top()] < temperatures[i])
            {
                const int index = stk.top();
                stk.pop();
                answer[index] = i - index;
            }
            stk.push(i);
        }
        return answer;
    }
};