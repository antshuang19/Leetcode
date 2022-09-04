class Solution:
    def longestPalindrome(self, s: str) -> str:
        memo ={}
        def polidrome(left, right):
            state = (left,right)
            if state in memo: return memo[state]
            if s[left] !=  s[right] : return False
            if left >= right : return True
            memo[state] = polidrome(left+1,right-1)
            return memo[state]
        N = len(s)
        result =""
        for i in range(N):
            for j in range(i,N):
                if (j-i +1) > len(result) and polidrome(i,j):
                    result = s[i:j+1]
        return result;
