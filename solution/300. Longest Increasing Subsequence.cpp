class Solution {
public:
    int first_greater_equal(vector<int>& nums,int target)
    {
        return lower_bound(begin(nums), end(nums),target)-begin(nums);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tail;
        for(const int number : nums)
        {
            if(tail.empty() or number > tail.back())
            {
                tail.push_back(number);
            }
            else
            {
                tail[first_greater_equal(tail,number)] = number;
            }
        }
        return tail.size();
    }
};