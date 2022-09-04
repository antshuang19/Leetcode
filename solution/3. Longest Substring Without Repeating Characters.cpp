class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int answer =0;
        vector<int> count(128);
        for(int left =0, right =0; right < s.size();right++)
        {
            ++count[s[right]];
            while(count[s[right]] > 1)
            {
                --count[s[left++]];
            } 
            answer = max(answer,right-left+1);
        }
        return answer;
    }
};