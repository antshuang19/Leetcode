class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0) return 1;
        int answer =10;
        int unique_digits = 9;
        for(int i=9; i > 0 and n >1;--n,--i)
        {
            unique_digits *= i;
            answer = answer + unique_digits;
        }
        return answer;
    }
};