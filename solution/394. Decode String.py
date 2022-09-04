class Solution:
    def decodeString(self, s: str) -> str:
        stack=[]
        for i in range(len(s)):
            if (s[i] != ']'):
                stack.append(s[i]);
            else:
                temp=""
                while stack[-1] != '[':
                    temp = stack.pop() + temp
                stack.pop()
                nums=""
                while(stack and stack[-1].isdigit()):
                    nums = stack.pop() + nums
                stack.append(int(nums) * temp)
        return ''.join(stack)