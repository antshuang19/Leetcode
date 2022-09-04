class Solution {
public:
    // lower bound function to find the posisition of our target
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
        if(left == nums.size() or nums[left] != target)
            return {-1,-1};
        int right = upper_bound(nums.begin(),nums.end(),target) - nums.begin()-1;
        return {left,right};
    }
};