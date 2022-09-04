class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        int answer = nums[0]+nums[1]+nums[2];
        sort(begin(nums),end(nums));
        
        for(int i =0; i< nums.size();i++)
        {
            if(i > 0 and nums[i] == nums[i-1])
                continue;
        
            int left = i+1;
            int right= nums.size()-1;
            while(left < right)
            {
                int sum = nums[i]+nums[left]+nums[right];
                if(sum == target)
                    return sum;
                if(abs(sum-target) < abs(answer-target))
                    answer = sum;
                if(sum < target)
                    left++;
                else 
                    right--;
            }
        }
        return answer;
    }
};