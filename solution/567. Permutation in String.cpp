class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        vector<int> count(128);
        int temp = s1.length();
        for (const char a : s1)
            count[a]++;

        for (int left = 0, right = 0; right < s2.size(); right++)
        {
            if (--count[s2[right]] >= 0)
                temp--;
            while (temp == 0)
            {
                if (right - left + 1 == s1.length())
                    return true;
                if (++count[s2[left++]] > 0)
                    temp++;
            }
        }
        return false;
    }
};