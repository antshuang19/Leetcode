class Solution
{
public:
    bool static compare(int a, int b)
    {
        return to_string(a) + to_string(b) > to_string(b) + to_string(a);
    }
    string largestNumber(vector<int> &nums)
    {
        string answer;
        sort(begin(nums), end(nums), compare);
        for (const int num : nums)
        {
            answer += to_string(num);
        }
        return answer[0] == '0' ? "0" : answer;
    }
};