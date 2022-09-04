class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.size()==1)
            return;
        int left = 0, right = nums.size()-1, current =0;
        while(current<= right)
        {
            if(nums[current]==0)
            {
                swap(nums[current++],nums[left++]);
                cout<<nums[0]<<" "<<nums[1]<<endl;
            }
            else if(nums[current]==2)
            {
                swap(nums[current],nums[right--]);
            }
            else
            {
                current++;
            }
        }
    }
};