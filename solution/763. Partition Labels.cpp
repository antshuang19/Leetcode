class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        vector<int> count(128);
        vector<int> answer;
        int size = s.size();
        for (int i = 0; i < size; i++)
        {
            count[s[i]] = i;
        }
        int left = 0, right = 0;
        for (int i = 0; i < size; i++)
        {
            right = max(right, count[s[i]]);
            if (right == i)
            {
                answer.push_back(right - left + 1);
                left = i + 1;
            }
        }
        return answer;
    }
};