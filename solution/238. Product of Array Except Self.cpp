class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer(nums.size());
        vector<int> prefix(nums.size(),1);
        vector<int> postfix(nums.size(),1);
        
        for(int i =1;i < nums.size();i++)
        {
            prefix[i] = prefix[i-1] * nums[i-1];
        }
        for(int i =nums.size()-2; i >=0; i--)
        {
            postfix[i] = postfix[i+1] * nums[i+1];
        }
        for(int i =0; i < nums.size();i++)
        {
            answer[i] = prefix[i] * postfix[i];
        }
        return answer;
    }
};