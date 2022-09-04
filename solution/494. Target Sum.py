class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        dp ={}
        def backtracking(i, total):
            if i == len(nums):
                if total == target:
                    return 1
                else :
                    return 0
            if (i,total) in dp :
                return dp[(i,total)]
            dp[(i,total)] = backtracking(i+1,total+nums[i]) + backtracking(i+1,total - nums[i])
            return dp[(i,total)] 
        return backtracking(0,0)
            
        