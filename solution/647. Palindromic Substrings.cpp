class Solution {
public:
    int counting_polidrome(string s,int left , int right)
    {
        int answer =0;
        while(left >=0 and right < s.size() and s[left]==s[right])
        {
            answer++;
            left--;
            right++;
        }
        return answer;
    }
    int countSubstrings(string s) {
        int answer =0;
        for(int i =0; i < s.size();i++)
        {
            answer+=counting_polidrome(s,i,i);
            answer+=counting_polidrome(s,i,i+1);
        }
        return answer;
    }
};