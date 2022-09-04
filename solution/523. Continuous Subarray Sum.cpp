class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> hashmap{{0,-1}};
        int size = nums.size();
        int prefix=0;
        for(int i =0; i < size;i++){
            prefix+= nums[i];
            if(k != 0)
                prefix = prefix % k;
            if(hashmap.count(prefix))
            {
                if(i - hashmap[prefix] > 1) // that more than two elemnts
                    return true;
            }
            else 
                hashmap[prefix] = i;
        }
        return false;
    }
};